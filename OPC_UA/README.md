# Setting up an OPC UA server on a KUNBUS Revolution Pi 3

This guide describes, how to set up an OPC UA server on a
[KUNBUS Revolution Pi 3](https://revolution.kunbus.de/) (RevPi) using
[open62541](https://open62541.org/) from zero.



0.  Start by assembling the Revolution Pi and connecting the different modules /
    gateways. Since there already exists a great [official tutorial](https://revolution.kunbus.com/tutorials/quick-start-guide/?noredirect=en_US)
    concerning this process from KUNBUS, this document focusses more on the
    software site of the set up procedure.

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

    Note: If you are experiencing trouble when changing locales, you might
    have to manually enable the generation of the locale you want to set first.
    Just remove the # infront of the respective entry in /etc/locale.gen and
    re-run raspi-config afterwards.

    UPDATE YOUR SYSTEM AFTERWARDS BY EXECUTING

        sudo apt-get update
        sudo apt-get upgrade

    You might have to run this multiple times to get all updates and upgrades!
    (This needs internet-connection, so if you don't have the possibility to
    connect the RPI via ethernet, you might consider postponing this step until
    after you have set up a WiFi-connection (cf. step 5).)

    Note: If you're running on Raspbian Jessy or below, you will have to upgrade
    to Stretch (or higher) later on anyways, so it might be a good idea to do
    this now. An instruction on how to do this can be found on the
    [official Raspberry website](https://www.raspberrypi.org/blog/raspbian-stretch/).

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

7.  Befor being able to actually use the modules / gateways connected to the
    RevPi, they have to be configured using the built-in tool PiCtory. First off,
    evaluate that all modules have been correctly connected to the core by typing

        piTest -d

    This should result in an overview of all connected devices. Yet, most likely,
    it will be stated that the modules have not been configured. To do so,
    connect to the Core by typing in its IP-address in the browser of your choice
    on a PC / laptop / etc. in the same network as the RevPi itself. You will be
    able to access PiCtory from the web server hosted on the device (credentials
    on the sticker on the side of the casing again). From this point on, simply
    follow the instructions found [here](https://revolution.kunbus.com/tutorials/was-ist-pictory/).

    Attention: To be able to access the web server, port 80 must not be blocked
    by your firewall!

8.  After finishing the configuration, it is recommended to update the modules /
    gateways following the instructions that can be found [here](https://revolution.kunbus.com/tutorials/expansion-modules-firmware-update/).
    Simply disconnect all modules except the one to update from the RevPi Core
    and execute

        piTest -f

9.  Now, to actually be able to access the DI / DO modules of the RevPi, an
    interface / API is needed. In analogy to the principles of modern software
    development, it is recommended to split the actual functionality of the
    connected peripheral devices in logical function blocks with highest possible
    coherence and low coupling, leading to a highly modular architecture on this
    layer. Doing this whilst considering the real-time requirements of the
    individual sub-modules at the same time allows for the actual process logic
    to be implemented on an arbitrary higher layer by abstracting the actual
    hardware interactions to an API level.

    1.

10. Now the last thing to do after creating the software interface is to set
    up the actual OPC UA server:

    1.  In this guide, we're using the open source OPC UA stack [open62541](https://open62541.org/)
        for the creation of our OPC-server. Begin by cloning the repository from
        GitHub via

            git clone https://github.com/open62541/open62541
            cd open62541
            git submodule init
            git submodule update

    2.  Follow the [Building open62541](https://open62541.org/doc/current/building.html)
        section from the official documentation to build the library. Concerning
        the additional build options, it is recommended to at least activate
        encryption (UA_ENABLE_ENCRYPTION) for security reasons (cf. below).
        Furthermore, O2-level compiler optimization can be chosen by setting
        CMAKE_BUILD_TYPE to RelWithDebInfo to increase the performance, which
        again leads to a better real-time behaviour.

        Attention: To be able to install all the dependencies necessary to build
        open62541 with the UA_ENABLE_ENCRYPTION enabled, a Raspbian version Stretch
        or higher is needed. So, if you are running on Jessy (or below), you need
        to upgrade your operating system first. An instruction on how to do so
        can e.g. be found on the [official Raspberry website](https://www.raspberrypi.org/blog/raspbian-stretch/).

    3.  It is possible to define the structure of your OPC-server using an
        externall tool like e.g. [Free OPC UA Modeler](https://github.com/FreeOpcUa/opcua-modeler)
        and import the generated model on compile time. This makes it possible
        to completely seperate the server as an abstract, reusable object from
        the process logic included in the nodeset, thus simplifying
        later changes to the latter enormously. To do so, export your model
        as an XML file and parse it to a C-library using the open62541 XML
        Nodeset Compiler that can be found under

            ${PATH_TO_OPEN62541}/tools/nodeset_compiler/nodeset_compiler.py

        An example on how to compile use the compiler can be found in
        ./model/parse_model.sh. For further information, refer to the
        [official documentation](https://open62541.org/doc/current/nodeset_compiler.html).

    4.  Build your OPC UA-server and compile it. An example implementation can
        be found under ./opcua/main/main.c. Again, for further information
        besides the source code documentation refer to the
        [official documentation](https://open62541.org/doc/current/server).

        Note: It is highly recommended to use the Basic256Sha256 endpoint security
        policy as well as the user-access plugin to prevent illicit access and to
        be able to guarantee safe communication between server and client.
        To generate the needed certificates and keys, execute cert_gen.sh (cf.
        ./scripts).

        Annotation: We're going to use a self signed CA-certificate. Whilst
        this is not recommended in the world wide web, it is sufficient to
        provide encrypted communication inside a closed sub-network.

    5.  What is left to do is to make sure that our OPC-server is automatically
        started on every boot up. This can be achieved by using Raspbians systemd
        initialization process. Start by creating a new file opcua.service.
