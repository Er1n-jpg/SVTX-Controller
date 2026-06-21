
# What is this?
Sound voltex is a popular japanese arcade rythmn game that involves the player pressing 6 buttons and turning two knobs (think piano tiles but extra steps!). I made a mini sound voltex controller, featuring the same 6 buttons along with two rotary encoders and a custom 3D printed case. 

<img width="270" height="366" alt="image" src="https://github.com/user-attachments/assets/aa31a898-c009-4cf7-b4ef-0a0100e13b74" />

it's played on arcade cabinets like this ^^

# Why this project? 
Since I was a kid, i've always wanted to play japananese arcade rythmn games but it's super hard to find cabinets here in Canada without having to travel hundreds of miles or literally just fly to japan. I was first introduced to the minivoltex through a youtube video when I was bored in 2020, back then I thought it was a super cool controller and a way for me to actually experience these arcade cabinets without having to haul myself to japan. When I was doing the blueprint hackpad tutorials, I kept thinking that the stuff I was doing, with macropads and all could relate back to rythmn game controllers and I thought OH! I could probably modify this to become a minivoltex and then play sound voltex and be happy :D. 

I haven't made the firmware for this project yet but come back later for a finished controller! 

Here are some examples of my inspiration 

<img width="605" height="305" alt="image" src="https://github.com/user-attachments/assets/8e78d820-1ce4-4e26-b88b-a656157daed1" />


My controller features:
- A Rasberry pi pico
- 7 MX cherry switches
- 7 diodes
- 2 LED neopixes
- 2 EC11 rotary encoders
- A buzzer, because why not!

# PCB
Here are my traces, models and schematic of my pcb (unupdated)

<img width="3507" height="2480" alt="image" src="https://github.com/user-attachments/assets/2be9fecd-775a-489e-b8f7-fc0c2167715c" />


This is my second time ever making a hardware project so alot of this repo stuff is named "hackpad" since it was originally going to be a hackpad.
Also the very first time i've ever tried to make a LED/encoder matrix and my very first time using rotary switch encoders and a first time for very very very many things (haha). 


Here's my traces!

<img width="827" height="647" alt="image" src="https://github.com/user-attachments/assets/e21e0b9d-6f22-4e67-9a80-75fe6a95a70d" />

I'm still not sure if i'm doing them right so ill need to ask some hardware smart friends for help lol. If anyone has reccomendations on where to put the neopixels it would be greatly appreciated

3D model of the PCB:

<img width="845" height="479" alt="image" src="https://github.com/user-attachments/assets/5a5da99f-49d1-4a3a-a49e-eee7b036d05d" />


# BOM

| Item | Description | Quantity (#) |	Price per unit | Shipping |	Total Price |
| --- | --- | --- | --- | --- | --- |
| Pi Pico |	Pi from PiShop	|	1 |	$5.56 |	$8.78 |	$14.31 |
| Rotary Encoder | From Aliexpress | 5 |	$0.96 |	Free | $4.79 |
| Cherry MX switches |	Also from Aliexpres yay	|	10 |	$0.43 |	Free |	$4.31 |
| Diodes |	From Aliexpress | 100 |	$0.04 |	Free |	$4.48 |
| Resistors |	Resistors from Aliexpress | 100 |	$0.03 |	Free	| $2.61 |
| Encoder Knobs | Knobs for rotary encoders on aliexpress | 2 | $3.38 | Free | $7.72 |
| Rubber Feet | Rubber feet to keep the keeb from sliding | 10 | 
| Total Price | --- | --- | --- | --- | $32.04 |

Huge mega thanks to all of my experienced hardware friends for helping me on building this (Tanishq, Sophia Duan, Owais, Jeremy) Yall are amazing hehe
