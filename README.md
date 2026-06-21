<img width="420" height="595" alt="image" src="https://github.com/user-attachments/assets/d889e3e9-6bd1-4c01-ad48-224dff2c7234" />


# What is this?
Sound voltex is a popular japanese arcade rythmn game that involves the player pressing 6 buttons and turning two knobs (think piano tiles but extra steps!). I made a mini sound voltex controller, featuring the same 6 buttons along with two rotary encoders and a custom 3D printed case. 

<img width="270" height="366" alt="image" src="https://github.com/user-attachments/assets/aa31a898-c009-4cf7-b4ef-0a0100e13b74" />

it's played on arcade cabinets like this ^^

# Why this project? 
Since I was a kid, i've always wanted to play japananese arcade rythmn games but it's super hard to find cabinets here in Canada without having to travel hundreds of miles or literally just fly to japan. I was first introduced to the minivoltex through a youtube video when I was bored in 2020, back then I thought it was a super cool controller and a way for me to actually experience these arcade cabinets without having to haul myself to japan. When I was doing the blueprint hackpad tutorials, I kept thinking that the stuff I was doing, with macropads and all could relate back to rythmn game controllers and I thought OH! I could probably modify this to become a minivoltex and then play sound voltex.

I make alot of my projects based on my interests (click that ivan with alien stage and ALD1flix for alpha drive one) so this is just another one down the pipeline, and I think its super cool to have an arcade emulator at home that you can play with. 

Here are some examples of my inspiration 

<img width="605" height="305" alt="image" src="https://github.com/user-attachments/assets/8e78d820-1ce4-4e26-b88b-a656157daed1" />


# PCB
Here are my traces, models and schematic of my pcb (unupdated)

<img width="3507" height="2480" alt="image" src="https://github.com/user-attachments/assets/2be9fecd-775a-489e-b8f7-fc0c2167715c" />


This is my second time ever making a hardware project so alot of this repo stuff is named "hackpad" since it was originally going to be a hackpad.
Also the very first time i've ever tried to make a LED/encoder matrix and my very first time using rotary switch encoders and a first time for very very very many things (haha). 


Here's my traces!

<img width="827" height="647" alt="image" src="https://github.com/user-attachments/assets/e21e0b9d-6f22-4e67-9a80-75fe6a95a70d" />


3D model of the PCB:

<img width="845" height="479" alt="image" src="https://github.com/user-attachments/assets/5a5da99f-49d1-4a3a-a49e-eee7b036d05d" />



Look at the case!

<img width="765" height="582" alt="image" src="https://github.com/user-attachments/assets/5b7baee5-9c76-4640-85df-e85e7e30213c" />

it's also my very first time decorating a case and personalizing it, since alot of the popular minivoltex controllers have super cool designs on them, I tried to add some engravings and sigils onto mine!


# Firmware
unfortunately, you can't really pull the firmware of these gamecontrollers out of thin air from QMK like you can most macropads or keyboards since the keys are relatively far away from eachother. 
For this project I used the base code of speedypotato's pico game controller while taking snippets like LED's out. THE FIRMWARE IS NOT ORIGINAL I REPEAT IT IS NOT ORIGINAL
The doccumentation for this is sick as hell! You should totally check it out AGAIN I REPEAT THE FIRMWARE IS NOT MINE 

Speedy potato's doccumentation, its super cool definetly check it out! https://github.com/speedypotato/Pico-Game-Controller 

# BOM

| Item | Description | Quantity (#) |	Price per unit | Shipping |	Total Price |
| --- | --- | --- | --- | --- | --- |
| Pi Pico |	Pi from PiShop	|	1 |	$5.56 |	$8.78 |	$14.31 |
| Rotary Encoder | From Aliexpress | 5 |	$0.96 |	Free | $4.79 |
| Cherry MX switches |	Also from Aliexpres yay	|	10 |	$0.43 |	Free |	$4.31 |
| Diodes |	From Aliexpress | 100 |	$0.04 |	Free |	$4.48 |
| Resistors |	Resistors from Aliexpress | 100 |	$0.03 |	Free	| $2.61 |
| Encoder Knobs | Knobs for rotary encoders on aliexpress | 2 | $3.38 | Free | $7.72 |
| Rubber Feet | Rubber feet to keep the keeb from sliding | 10 | $1.78 | Free | $ 3.56 |
| Total Price | --- | --- | --- | --- | $41.79 |

All other items I currently have or are included in a 50+ set for my other projects, this includes 3D prinding and filament

Huge mega thanks to all of my experienced hardware friends for helping me on building this (Tanishq, Sophia Duan, Owais, Jeremy) Yall are amazing hehe
