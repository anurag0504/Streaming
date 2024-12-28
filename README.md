# Streaming
Screen Capture and Remote Viewer Application
Screen Capture and Remote Viewer Application
This application contains two applications designed to work together to enable screen capture and streaming to a remote viewer:
Screen Capture Application: Captures the screen of the host system and streams it to a specified remote viewer over the network.
Remote Viewer Application: Receives and displays the streamed video from the Screen Capture Application.
Steps to build and run: 
1.	Firstly clean/ clear the cmakeconfigurations.
2.	Then Select Run Cmake 
3.	Then Build the application
4.	Then run the application
5.	In case of any errors please clean again and rebuild and then run the application.
Screen Capture Application 
•	Captures the host system's screen in real-time.
•	Streams the captured screen to a remote viewer using RTP.
•	Logs GStreamer process output and errors for debugging.
•	Provides input fields for specifying the remote viewer's IP address and port.
•	GUI-based control to start and stop screen sharing.
When you run the application
1.	You get the following output: 
 
2.	Enter the Ip as 127.0.0.1 as the local ip to run in same machine
3.	Enter the port as 5000
4.	Press Start Screen Sharing to stream in the remote application.
 

Remote Viewer Application
•	Receives RTP video streams and renders them in a GUI.
•	Displays real-time video streamed from the Screen Capture Application.
•	Configurable port for receiving the video stream.
•	Supports video decoding and rendering using GStreamer.
When you run the application
1.	You get the following output:  

2.	Enter the senders ip as 127.0.0.1 and port as 5000 
3.	Press view remote screen button to see the stream.
 

When both the following applications are run simultaneously then we get the following output:
Wait for few seconds to see the stream on the remote application as it might take some time to get streamed.

 


