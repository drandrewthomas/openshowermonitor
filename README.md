###Open Shower Monitor

##Introduction

This is the home of the open shower project, which hopes to inspire people to use their Maker skills to monitor the amount of water they use when showering. Hopefully, as well as making people more aware of just how much water a simple shower can use, it could help make you more eco-efficient. Also, it seems like a fun project :-)

The open shower monitor includes details for building a very simple Arduino-based flow logger, with simple Bluetooth communications for downloading the data. It includes for measuring flow rates averaged over each five second period, so gives plenty of data on which to base improved showering strategies.

Also, a little caveat: mixing water and electricity can be dangerous, so please don't connect your monitor to a high voltage (e.g. mains) electrcity supply. This project is designed to be used with a small battery supply, isolated from the shower hose, and the wireless communications mean you don't need a computer anywhere near the shower and water. If you don't know what you're doing, make sure you seek advice from an electrician and plumber.

I hope you have some warm, wet, Makery fun :-)

##How to use it

As the photo of my setup shows, I put the circuit and battery in a plastic bag with only the flow meter wires emerging from it. Then I used tape to seal the bag, although there's no reason why the circuit can't be built into a waterproof box. Then the circuit can be connected to a PC or Android tablet over Bluetooth using a serial terminal (e.g. the Arduino serial monitor, or BlueTerm on Android). Data from the circuit will then stream to your computer and when you have enough you can save it to a text document, with a csv extension, and open it in a spreadsheet to graph the flow rates.
