# Upload over the air 
How to upload code with out the need of a cable 

## Set up da lib
### First include the libs : 
- AsyncTCP.h
- ESPAsyncWebServer.h
- AsyncElegantOTA.h 
 You can do it be the Plataform IO libs management or copy from .pio/libsdeps from this repo 
### Than add the upload.h librabry from this repe
- in the setup of your code add the function "upload_OTA("SSD","PASSWORD")"
- Change the SSD and PASSWORD to your wi-fi credencial 
- Now everthing should work and compile 
## How to upload 

# Get the ip 
- In the serial monitor should print the ip of the ESP 
- You should be able to get the ip by  your router 
- In the browser time the ip 
- Should load the page 
# Upload 
- Now go to ip/upload 
- We are going to upload the .bin file. This file is binary with is basicaly your code compiled 
- Aftet the build go to this path  /.pio/build/PROJECT_NAME/firmware.bin. If can't find the .pio it's because it's a hidden file, look up how to show hidden file in yout SO 
- In ip/upload make share it's checked firmware and show to the eleganteOTA page the firmware.bin file 
- That's it, make share that every file you upload have the upload_ota function so you can keep uploading over the air. 
