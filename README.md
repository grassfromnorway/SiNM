# SiNM (Screenshot into Note Manager)
Made for if you've ever wanted to just be able to take that image and have it on your screen for future reference / lookats. Personally, i've always hated that there was no easy way to view the screenshots you took, except saving them and opening them as a image. This is  exactly the inspiration behind this project, to fix that gap and be able to work faster and more seamlessly.

## V1.0.0
**Info:** \
Version 1.0.0 is simply a MVP of the project that i made over the weekend. More features are to be expected. \
**Contents:**
- A very basic UI / UX for pure functionality
- Working screenshot tool to capture those moments for later view.
### Dependencies

  - C++ Compilator version 17.x.x or later
  - Qt 6 or later
  - Make 4.3 or later
  - CMake 3.28.3 or later
  - Git 2.43.0 or later

*It is possible that earlier versions will work, but these **are** the versions that the project was intended to be used with*

### Todo for v2.x.x:
- Improve UI
- Clean up code
- Implement more features:
- - Global hotkey recognition for Linux (X11) //higher priority
- - Global hotkey recognition for Linux (Wayland)
- - Easier screenshot UI managing
- Much, much more.

### How to build
 1. Pull the github repo locally
 2. Open your terminal and change directories into your CMake folder
 3. Run ```cmake ..``` to build the make files
 4. Run ```make``` to build the executable
 5. Run ```./SiNM``` in order to execute the program

 I suggest running it in the background with the & symbol after ```./SiNM&```, and if there's any debug prints (shouldn't be) pipe it into /dev/null

### License
This project is licensed under the GNU General Public License v3.0 (GPL-3.0). 

This means you are free to use, modify, and distribute this software, but any derivative work must also be released under the GPL-3.0 license. See the **LICENSE** file for full details.

