#include <gtk/gtk.h>
#include <string>
#include <iostream>

GtkWidget *entry;

static void button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *label = gtk_button_get_label(GTK_BUTTON(widget));
    const gchar *current = gtk_entry_get_text(GTK_ENTRY(entry));
    std::string text = current;
    
    if (strcmp(label, "=") == 0) {
        // Evaluate expression
        try {
            // Very basic evaluation - in real calculator would need proper expression parsing
            double result = std::stod(text);
            text = std::to_string(result);
        } catch (...) {
            text = "Error";
        }
    } else if (strcmp(label, "C") == 0) {
        text = "";
    } else {
        text += label;
    }
    
    gtk_entry_set_text(GTK_ENTRY(entry), text.c_str());
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    
    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);
    
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);
    
    const char *buttons[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", ".", "=", "+",
        "C"
    };
    
    int i = 0;
    for (int row = 1; row < 5; row++) {
        for (int col = 0; col < 4; col++) {
            if (i < 16) {
                button = gtk_button_new_with_label(buttons[i]);
                gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
                g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);
                i++;
            }
        }
    }
    
    // Add clear button
    button = gtk_button_new_with_label(buttons[16]);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 4, 1);
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);
    
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    
    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    
    return status;
}
