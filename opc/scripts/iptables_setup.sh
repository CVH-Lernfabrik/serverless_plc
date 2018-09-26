#!/bin/bash

############### Configuration ################
# Flush the current configuration
sudo iptables -F

# Accept connections on the loopback
sudo iptables -A INPUT -i lo -j ACCEPT
sudo iptables -A OUTPUT -o lo -j ACCEPT

# Accept connections via SSH
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT
sudo iptables -A OUTPUT -p tcp --sport 22 -j ACCEPT

# Allow NTP lookups
sudo iptables -A INPUT -p udp --sport 123 -j ACCEPT
sudo iptables -A OUTPUT -p udp --dport 123 -j ACCEPT

# Allow DHCP lookups
sudo iptables -A INPUT -p udp --sport 67:68 -j ACCEPT
sudo iptables -A OUTPUT -p udp --dport 67:68 -j ACCEPT

# Allow DNS lookups
sudo iptables -A INPUT -p udp --sport 53 -j ACCEPT
sudo iptables -A OUTPUT -p udp --dport 53 -j ACCEPT

# Accept connections from port 80 (HTTP)
sudo iptables -A INPUT -p tcp --sport 80 -j ACCEPT
sudo iptables -A OUTPUT -p tcp --dport 80 -j ACCEPT

# Accept connections on port 80 (HTTP)
sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT
sudo iptables -A OUTPUT -p tcp --sport 80 -j ACCEPT

# Accept connections on port 443 (HTTPS)
sudo iptables -A INPUT -p tcp --sport 443 -j ACCEPT
sudo iptables -A OUTPUT -p tcp --dport 443 -j ACCEPT

# Accept connections on port 4840 (OPC UA)
sudo iptables -A INPUT -p tcp --dport 4840 -j ACCEPT
sudo iptables -A OUTPUT -p tcp --sport 4840 -j ACCEPT

# Protection against some basic DDOS-attack-patterns
iptables -A INPUT -p tcp --tcp-flags ALL NONE -j DROP
iptables -A INPUT -p tcp ! --syn -m state --state NEW -j DROP
iptables -A INPUT -p tcp --tcp-flags ALL ALL -j DROP

# Reject all other network traffic
sudo iptables -A INPUT -j REJECT
sudo iptables -A OUTPUT -j REJECT

######### Set up saving and loading ##########
# Load and save scripts
IPTABLESLOAD=/etc/network/if-pre-up.d/iptablesload
IPTABLESSAVE=/etc/network/if-post-down.d/iptablessave

# Iptables rules
IPTABLESRULES=/etc/network/iptables.rules

# Check, if the load and save scripts already exist and create them if not
if ! [ -f $IPTABLESLOAD ]; then
        sudo touch $IPTABLESLOAD
fi
if ! [ -f $IPTABLESSAVE ]; then
        sudo touch $IPTABLESSAVE
fi

# Make the load and save scripts executable
sudo chmod 777 $IPTABLESLOAD
sudo chmod 777 $IPTABLESSAVE

# Write the load script
sed -e 's/^.*&&& //' > $IPTABLESLOAD << EndLoad
        &&& #!/bin/bash
        &&& iptables-restore < $IPTABLESRULES
        &&& exit 0
EndLoad

# Write the save script
sed -e 's/^.*&&& //' > $IPTABLESSAVE << EndSave
        &&& #!/bin/bash
        &&& iptables-save > $IPTABLESRULES
        &&& exit 0
EndSave
