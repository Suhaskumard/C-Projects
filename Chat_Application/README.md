# 💬 Chat Application in C (GUI + Sockets)

## 📌 Overview

This project is a simple real-time chat application built using **C programming**, **socket programming**, and **GTK for GUI**. It demonstrates client-server communication with a graphical interface.

---

## 🚀 Features

* Real-time messaging
* Client-Server architecture
* GUI-based chat (no CLI)
* Lightweight and fast
* Uses TCP sockets

---

## 🛠️ Technologies Used

* C Programming
* Socket Programming (TCP/IP)
* GTK (GUI Library)

---

## 📂 Project Structure

\`\`\`
chat-app/
│
├── server.c        # Server-side code
├── client_gui.c    # GUI Client
├── README.md
\`\`\`

---

## ⚙️ Installation & Setup

### 1. Install Dependencies

\`\`\`
sudo apt install libgtk-3-dev
\`\`\`

### 2. Compile

\`\`\`
gcc server.c -o server
gcc client_gui.c \`pkg-config --cflags --libs gtk+-3.0\` -o client
\`\`\`

### 3. Run Application

\`\`\`\n./server\n./client\n\`\`\`\n\n## 🪟 Windows 11 Setup (Recommended: WSL)\n\n**Easiest method - Use WSL (Windows Subsystem for Linux):**\n\n1. Install WSL: `wsl --install -d Ubuntu`\n2. Open Ubuntu terminal (search \"Ubuntu\" in start menu)\n3. cd to project dir, follow Linux instructions above\n\n**Alternative: Native Windows (requires code porting):**\n\n1. Install [MSYS2](https://www.msys2.org/)\n2. MSYS2 MinGW x64 terminal:\n   \`\`\`\npacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gtk3 mingw-w64-x86_64-pkg-config\n\`\`\`\n3. **Port code to Winsock** or use WSL (POSIX headers not available natively).\n\n**Note:** Current code uses Linux/POSIX sockets & GTK. WSL is recommended for immediate testing.

---

## 📡 How It Works

* Server listens on port **8080**
* Client connects using **localhost**
* Messages are sent and received via TCP sockets
* GTK provides GUI for sending and displaying messages

---

## 🔮 Future Improvements

* Multi-client support
* Usernames
* Chat history storage
* File sharing
* Encryption (secure chat)

---

## 👨‍💻 Author

Suhas Kumar

---

## ⭐ If you like this project, give it a star!


