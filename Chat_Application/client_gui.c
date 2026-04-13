#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080 

int sock;
GtkWidget *text_view;
GtkWidget *entry;

// Append message to chat box
void append_text(const char *msg) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &amp;end);
    gtk_text_buffer_insert(buffer, &amp;end, msg, -1);
}

// Send message
void send_message(GtkWidget *widget, gpointer data) {
    const gchar *msg = gtk_entry_get_text(GTK_ENTRY(entry));

    if (strlen(msg) > 0) {
        send(sock, msg, strlen(msg), 0);

        char display[1100];
        snprintf(display, sizeof(display), "You: %s\n", msg);
        append_text(display);

        gtk_entry_set_text(GTK_ENTRY(entry), "");
    }
}

// Receive messages
gboolean receive_message(gpointer data) {
    char buffer[1024] = {0};
    int valread = read(sock, buffer, 1024);

    if (valread > 0) {
        char display[1100];
        snprintf(display, sizeof(display), "Server: %s\n", buffer);
        append_text(display);
    }

    return TRUE;
}

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &amp;serv_addr.sin_addr);

    connect(sock, (struct sockaddr *)&amp;serv_addr, sizeof(serv_addr));

    gtk_init(&amp;argc, &amp;argv);

    GtkWidget *window, *vbox, *sendBtn;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Chat Client");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 500);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_box_pack_start(GTK_BOX(vbox), text_view, TRUE, TRUE, 5);

    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 5);

    sendBtn = gtk_button_new_with_label("Send");
    g_signal_connect(sendBtn, "clicked", G_CALLBACK(send_message), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), sendBtn, FALSE, FALSE, 5);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Poll for messages
    g_timeout_add(500, receive_message, NULL);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}

