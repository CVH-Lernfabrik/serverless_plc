# Setting up AWS Greengrass on a Raspberry Pi

This guide describes, how to set up an AWS Greengrass instance on a Raspberry Pi
(RPI) from zero. Since there already exists a great [official tutorial](http://docs.aws.amazon.com/de_de/greengrass/latest/developerguide/gg-tutorial-rpi.html#gg-tutorial-rpi-set-up-pi)
concerning the process from the AWS site (meaning how to create a new Greengrass
group in AWS IoT, how to add devices, etc.), this document focusses more on the
RPI site of the set up procedure.

1.  Download the latest version of Raspbian (though this is not mandatory, I
    would recommend to use the light-version, since this minimalistic set-up
    is free of all the (for this task) superfluous features that come along
    with the full version (I'm looking at you, MinecraftPI!))

2.  Flash the SD card using a tool like ImageWriter (if you are using Windows)
    or dd (if you are using Linux or Mac OS; might look like this:

        sudo dd bs=4M if=/home/lukas/Downloads/2017-04-10-raspbian-jessie-lite.img of=/dev/mmcblk0

    )

3.  Enable SSH by crating an empty file called ssh on the boot partition of
    the SD card. Make sure, that the default SSH-port (port 22) isn't blocked
    by your firewall!

4.  Eject the SD card and plug it into the RPI, start it up and, if necessary,
    connect to it via SSH. The default login data is:

        username: pi
        password: raspberry

    Attention: The default keyboard-layout is set to gb, so y and z are switched.

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

5.  Set up the RPI's network-configuration:

    Edit /etc/wpa_supplicant/wpa_supplicant.conf and add the following lines
    at the end:

        network={
            ssid="your_network_SSID"
            psk="your_WiFi_password"
        }

    Furthermore, add

        auto wlan0

    to the wlan0-part in /etc/network/interfaces. This will enable the
    interface on boot. If you want to have a static IP-address rather than
    receiving one via DHCP, replace the line

        iface wlan0 inet manual

    by

        iface wlan0 inet static

    and add the follwing block directly afterwards:

        address   192.168.42.42   # Your address
        netmask   255.255.255.0   # Netmask to use
        gateway   192.168.42.1    # Usually your router
        network   192.168.42.0    # Your network's address range (optional)
        broadcast 192.168.42.255  # Broadcast address (optional)

    Finally, to enable auto-reconnect on a connection loss,
    execute the following command:

        sudo cp -s /etc/wpa_suppliciant/ifupdown.sh /etc/ifplugd/action.d/ifupdown

6.  What we are still lacking though is a firewall to constrain the network
    traffic. This is a very important security measure to restrict possible
    unauthorized instances from messing with the server or the nodes. In
    Raspbian, as well as in Linux in general, firewall rules are managed by
    the program iptables by default. Now, it is generally advisable to configure
    the firewall in a way, that only the needed ports are accessible. An example
    of how to do this is provided in form of the script iptables_setup.sh.

7. AWS Greengrass:
    -   To set up AWS Greengrass respectively on the RPI as well as on AWS IoT,
        follow along the official [AWS tutorial](http://docs.aws.amazon.com/de_de/greengrass/latest/developerguide/gg-tutorial-rpi.html#gg-tutorial-rpi-set-up-pi).
    -   Once finished setting up AWS Greengrass, there are only two things left
        to do. The first one is to think of a way to make the GGC (Greengrass
        Core) software automatically start on every boot up. This is not only
        very convenient for us as users in terms of automatization, but also a
        crucial thing to do to minimize the downtime of our system (e.g. in
        cases of power outage, etc.).
        Therefor we will use Raspbians systemv initialization process [\*].
        Start by creating a file /etc/init.d/greengrass, that looks like the
        provided equivalent. Make it executable via

            sudo chmod 755 /etc/init.d/greengrass

        After that, execute

            sudo update-rc.d greengrass defaults

        Now the GGC software will automatically start on every boot
        up. Furthermore, it can be manually started and stopped via

            sudo service greengrass start/stop/restart

        [\*] Annotation: On a Raspberry Pi, it would also be possible to
        use systemd instead of systemv, but since not all Linux distributions
        use the former yet, I decided to use systemd with regards to portability
        and inter-platform compatibility.
    -   The absolutely last thing left to do is to manually enable the cgroup
        memory submodule. If you already tried to commit sth. from AWS IoT to
        your Greengrass Core and restart the software afterwards, you may have
        seen some nasty looking errors. The reason for that is, that the local
        Lambda container on the RPI isn't able to be initialized without the
        above mentioned module. To fix this, add

            cgroup_memory=1

        before

            elevator=deadline

        in /boot/cmdline.txt (this was recently changed from

            cgroup_enable=memory,

        so if you are using an older version of Raspbian, that might be the
        command to go with).

    -   Optional: To be able to host AWS Lambda functions written in Node.js 6.10
        on the GGC, it is necessary to install the respective runtime first. On
        a Raspberry Pi, this can be done by

            curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -
            sudo apt-get install nodejs

        Rename the executable /usr/bin/node to /usr/bin/nodejs6.10 afterwards
        (the actual version does not matter as long as it is above 6.10).
