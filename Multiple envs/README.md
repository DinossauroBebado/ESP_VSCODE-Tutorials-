# Tutorials
This repo is for teaching and learning code related tools 

## Multiple Envs 
How to have multiples test codes in the same project ??  
The easiest way is the separet the code in diferent folders and then edit the <b>platformio.ini</b> file  
### Plataformio.ini 
This file is responsable for all the configs of the project so things like baud rate, port and board are all set here  
Here you need to create a new env like so :

``` 
[env:One]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino


[env:Two]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino

``` 
Now you have two enviroments the One and Two. To change between them is in the botton of the page 

<img src = "https://media.discordapp.net/attachments/913213236793475073/980100066117304360/unknown.png?width=1012&height=616"> 

Them you need to add the src_filter this will select wich files you don't want to compile so for Env_two : 

``` 
src_filter = +<*> -<.git/> -<.svn/> -<Env_one>

```
And now plataform io should ignore all the files in the Env_one folder.  
Be careful thought and the libs you are using should be erased as well if you are not using then in that specific env 
