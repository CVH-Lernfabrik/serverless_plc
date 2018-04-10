# Setting up an OPC UA server on a KUNBUS Revolution Pi 3

This guide describes, how to set up an OPC UA server on a
[KUNBUS Revolution Pi 3](https://revolution.kunbus.de/) (RevPi) using
[open62541](https://open62541.org/) from zero.

1.  Connect your RevPi Core 3 to the router / network via the ethernet port.

2.  Get the IP-address of your Revolution Pi (e.g. by using a network scanner
    like nmap if you are using Linux or Mac OS; might look like this:

        sudo nmap -PS22 192.168.1.0/24

    )

3.  Connect to the RevPi via SSH. The default login data can be found on the
    sticker on side of the casing. Make sure, that the default SSH-port (port 22)
    isn't blocked by your firewall!

    Attention: The default keyboard-layout might be set to gb, so y and z might
               be switched.

    THE ABSOLUTELY FIRST THING YOU WANT TO DO IS TO CHANGE THIS DEFAULT
    USERNAME / PASSWORD COMBINATION! The easiest way to do this is via

        raspi-config

    (the RPI configuration tool). While you are at it, you might consider
    switching the locales (like timezone and especially keyboard-layout) as
    well. Also, expand the filesystem (under the point "Advanced Options") if
    you haven't done it already while setting up the SD card.

    UPDATE YOUR SYSTEM AFTERWARDS BY EXECUTING

        sudo apt-get update
        sudo apt-get upgrade

    You might have to run this multiple times to get all updates and upgrades!
    (This needs internet-connection, so if you don't have the possibility to
    connect the RPI via ethernet, you might consider postponing this step until
    after you have set up a WiFi-connection (cf. step 5).)

    The last thing we'll have to do before setting up the network interfaces
    is to affix the necessity of a password to the usage of sudo. Eventually,
    it's neither nice nor wished for, if anybody can mess with the RPI if
    an authorized person accidentally forgets to log out or close the SSH
    connection. This is done by changing /etc/sudoers.d/010_pi-nopasswd so
    that it looks like this

        pi ALL=(ALL) ALL: PASSWD

    You should also consider to rename the file to 010_pi-passwd for
    clarification.

5.  If you want to have a static IP-address rather than receiving one via DHCP,
    replace the line

        iface wlan0 inet manual

    by

        iface wlan0 inet static

    in /etc/network/interfaces and add the follwing block directly afterwards:

        address   192.168.42.42   # Your address
        netmask   255.255.255.0   # Netmask to use
        gateway   192.168.42.1    # Usually your router
        network   192.168.42.0    # Your network's address range (optional)
        broadcast 192.168.42.255  # Broadcast address (optional)

6.  What we are still lacking though is a firewall to constrain the network
    traffic. This is a very important security measure to restrict possible
    unauthorized instances from messing with the server or the nodes. In
    Raspbian, as well as in Linux in general, firewall rules are managed by
    the program iptables by default. Now, it is generally advisable to configure
    the firewall in a way, that only the needed ports are accessible. An example
    of how to do this is provided in form of the script iptables_setup.sh.

7. 
