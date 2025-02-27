# ntconnect (Debian)
C tool to facilitate the connection to networks from the Linux terminal.
This will edit the file /etc/network/interfaces to put the correct wireless network information inside.

# Installation
<ol>
<li>Install the package libiw-dev</li>

```bash
sudo apt install libiw-dev
```
<li>Clone the master branch of this repository</li>
	
```bash
git clone https://github.com/arkneid/ntconnect.git
```
<li>Enter the ntconnect folder and run make command</li>

```bash
cd ntconnect
make
```
<li>Now install ntconnect tool</li>	

```bash
sudo make clean install
```
</ol>

# Uninstall
<ol>
<li>Go to the previous clone git folder</li>

```bash
cd ntconnect
sudo make uninstall
```
</ol>

# Usage
Normal usage:

```bash
sudo ntconnect -s <network_ssid> -w <wireless_network_interface> -p <network_password>
sudo ifdown <wireless_network_interface>
sudo ifup <wireless_network_interface>
```

Portal usage:

```bash
sudo ntconnect -m portal -s <network_ssid> -w <wireless_network_interface>
sudo ifdown <wireless_network_interface>
sudo ifup <wireless_network_interface>
```

Print help:

```bash
sudo ntconnect -h or sudo ntconnect --help
```

Check History:
```bash
sudo ntconnect -H or sudo ntconnect --history
```

List WiFi networks:
```bash
sudo ntconnect -l or sudo ntconnect --list
```

# Author
arknied(https://github.com/arkneid)

# License
This software is released under the MIT License, see LICENSE.
