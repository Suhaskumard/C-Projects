# 💬 Chat Application in C (GUI + Socket Programming)

## 📌 Overview

This project is a **real-time chat application** built using **C programming**, **TCP socket programming**, and **GTK for graphical user interface (GUI)**.
It demonstrates client-server communication with a simple and interactive desktop interface.

--- 

## 🚀 Features

* 💬 Real-time messaging between client and server
* 🖥️ GUI-based chat interface (no command line)
* 🔌 TCP socket communication
* ⚡ Lightweight and fast
* 🧠 Easy-to-understand architecture

---

## 🛠️ Technologies Used

* **C Programming**
* **Socket Programming (TCP/IP)**
* **GTK (GUI Library)**

---

## 📂 Project Structure

```
Chat_Application/
│
├── server.c          # Server-side implementation
├── client_gui.c      # GUI client using GTK
├── README.md         # Project documentation
```

---

## ⚙️ Installation & Setup

### 1. Install GTK (Linux / WSL)

```
sudo apt update
sudo apt install libgtk-3-dev
```

### 2. Compile the Code

```
gcc server.c -o server
gcc client_gui.c `pkg-config --cflags --libs gtk+-3.0` -o client
```

### 3. Run the Application

```
# Start server first
./server

# Then run client
./client
```

### 🪟 Windows 11 Setup (Recommended: WSL)

**Easiest method - Use WSL (Windows Subsystem for Linux):**

1. Install WSL: `wsl --install -d Ubuntu`
2. Open Ubuntu terminal (search \"Ubuntu\" in start menu)
3. `cd /mnt/e/Projects/C-projects/Chat_Application`
4. Follow Linux instructions above

**Alternative: Native Windows (requires code porting):**

1. Install [MSYS2](https://www.msys2.org/)
2. MSYS2 MinGW x64 terminal:

pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gtk3 mingw-w64-x86_64-pkg-config
   
3. **Port code to Winsock** (replace arpa/inet.h with winsock2.h, add WSAStartup etc.) or use WSL.

---

## 📡 How It Works

* The **server** listens on port `8080`
* The **client** connects to the server using `localhost`
* Messages are sent and received via **TCP sockets**
* GTK provides a GUI for displaying and sending messages

---


## 🔮 Future Improvements

* 👥 Multi-client support (multiple users)
* 🧑 Username system
* 💾 Chat history storage
* 🔐 End-to-end encryption
* 🌐 Internet-based communication

---

## 🧠 Learning Outcomes

* Understanding of **socket programming**
* Basics of **GUI development in C**
* Client-server architecture
* Handling real-time data communication

---


