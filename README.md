# TFE-opensource-printer
An open source paper printer to make yourself!

This document and the project itself is verry much a work in progress, keep that in mind when reading. The code is not curently in a working state either.


wifi config [tutorial](https://www.raspberrypi.com/documentation/computers/configuration.html)

## Setting up the Raspberry
- 1. on a Raspberry with Raspberry Pi OS, in the `config.txt` add at the end :
    ``` conf
    dtoverlay=dwc2,dr_mode=peripheral
    ```
    this enables some functionality for the USB periferals, which we need for the trick to work.

- 2. **g_printer or g_printer0?**
    Before proceeding, you need to know what is the device name of the printer created by the g_printer library. This module is included in the kernel and is part of the USB gadget suite. you can find the official documentation [here](https://www.kernel.org/doc/Documentation/usb/gadget_printer.rst). To get the name do the following :
    ```
    sudo modprobe g_printer
    ls /dev
    ```
    Watch in the result for the name of the `g_printer`. Does it have a zero at the end? If so you dont have anything special to do.
    If it does not, you will nedd to modify the `controller.c` in the nex steps so that the value of `PRINTER_FILE` matches.

- 3. **GhostPDL**
    For the printer to print, we need to obtain the document in a bitmap format. To achieve it we need to use GhostPDL. The program will handle all conversions for us. Here are the steps :

    Install autoconf (it is necesary for the compilation process)
    ``` sh
    sudo apt-get update
    sudo apt-get install autoconf
    ```

    Dowload and compile GhostPDL
    ``` sh
    wget -O ghostpdl.tar.gz "https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs10031/ghostpdl-10.03.1.tar.gz"
    mkdir ghostpdl
    tar zxf ghostpdl.tar.gz -C ghostpdl --strip-components=1
    cd ghostpdl
    ./configure
    make
    ```

    Install it
    ```
    sudo ln bin/gpdl /bin/gpdl
    ```

- 4. **Istall the code**
    This project use a custom code in c to get printjobs from `g_printer` and send them to `ghostpdl` we also need a program to control the physical printer in order to print the document.

    Dowload and build
    ``` sh
    wget -O controller.c "https://github.com/mux99/TFE-opensource-printer/raw/main/Code/controller.c"
    gcc -Wall controller.c -o emulatedprinter
    ```

    Install
    ```
    sudo ln emulatedprinter /bin/emulatedprinter
    ```

- 5. **Run**
    When everything is ready, we simply need to start the programs like so :
    ``` sh
    sudo modprobe g_printer idVendor=0x03f0 idProduct=0x2404 iProduct="openPrinter" pnp_string="MFG:HP;MDL:Deskjet F2200 series;CMD:PS,PDF,PCL,PXL,XPS;CLS:PRINTER;"
    sudo chmod 666 /dev/g_printer0
    ./emulatedprinter -read_data
    ```


Stop `g_printer`
``` sh
sudo rmmod g_printer
sudo rmmod usb_f_printer
```



<!-- wget "https://github.com/WiringPi/WiringPi/releases/download/3.6/wiringpi_3.6_arm64.deb"
 sudo dpkg -i wiringpi_3.6_arm64.deb 
 
 gcc -o test test.c -l wiringPi-->