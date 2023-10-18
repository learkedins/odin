#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

/*
char *execute_command(const char *command) {
    char buffer[128];
    char *result = NULL;
    FILE *pipe = popen(command, "r");

    if (pipe) {
        result = malloc(1);
        result[0] = '\0';

        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL) {
                result = realloc(result, strlen(result) + strlen(buffer) + 1);
                strcat(result, buffer);
            }
        }

        pclose(pipe);
    }
}
*/

void file_set_callback(GtkFileChooserDialog *dialog, gint response_id, gpointer user_data) {
    if (response_id == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        const gchar *filename = gtk_file_chooser_get_filename(chooser);
        GtkWidget *entry = (GtkWidget *)user_data;
        gtk_entry_set_text(GTK_ENTRY(entry), filename);
    }

    gtk_widget_destroy(GTK_WIDGET(dialog));
}

void browse_button_clicked(GtkWidget *button, gpointer user_data) {
    GtkWidget *entry = (GtkWidget *)user_data;

    GtkWidget *dialog = gtk_file_chooser_dialog_new("Select a File",
            GTK_WINDOW(gtk_widget_get_toplevel(button)),
            GTK_FILE_CHOOSER_ACTION_OPEN,
            "Cancel", GTK_RESPONSE_CANCEL,
            "Open", GTK_RESPONSE_ACCEPT,
            NULL);

    g_signal_connect(dialog, "response", G_CALLBACK(file_set_callback), entry);

    gtk_widget_show_all(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ODIN");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget *vbox = gtk_vbox_new(FALSE, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    GtkWidget *hbox1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    GtkWidget *hbox2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    GtkWidget *hbox3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    GtkWidget *hbox4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);

    GtkWidget *ap, *bl, *csc, *cp, *home;
    GtkWidget *entryap, *entrybl, *entrycsc, *entrycp, *entryhome;
    GtkWidget *button, *button1, *button2, *button3, *button4;


    int *file_field[4][2] = {
        {ap, entryap, button},
        {bl, entrybl, button1},
        {csc, entrycsc, button2},
        {cp, entrycp, button3},
        {home, entryhome, button4}
    }

    for(int i = 0; i < 5; i++) {
        char label[] = toupper(file_field[i][0]);
        GtkWidget file_field[i][0] = gtk_label_new(file_field[i][0]);
        gtk_box_pack_start(GTK_BOX(hbox), file_field[i][0], FALSE, FALSE, 0);
    }

    GtkWidget *ap = gtk_label_new("AP");
    GtkWidget *entryap = gtk_entry_new();
    GtkWidget *button = gtk_button_new_with_label("Browse");
    gtk_entry_set_tabs(GTK_ENTRY(entryap), FALSE);
    gtk_widget_set_hexpand(entryap, TRUE);
    gtk_box_pack_start(GTK_BOX(hbox), ap, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), entryap, TRUE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 0);

    GtkWidget *bl = gtk_label_new("BL");
    GtkWidget *entrybl = gtk_entry_new();
    GtkWidget *button1 = gtk_button_new_with_label("Browse");
    gtk_entry_set_tabs(GTK_ENTRY(entrybl), FALSE);
    gtk_widget_set_hexpand(entrybl, TRUE);
    gtk_box_pack_start(GTK_BOX(hbox1), bl, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox1), entrybl, TRUE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(hbox1), button1, FALSE, FALSE, 0);

    GtkWidget *csc = gtk_label_new("CSC");
    GtkWidget *entrycsc = gtk_entry_new();
    GtkWidget *button2 = gtk_button_new_with_label("Browse");
    gtk_entry_set_tabs(GTK_ENTRY(entrycsc), FALSE);
    gtk_widget_set_hexpand(entrycsc, TRUE);
    gtk_box_pack_start(GTK_BOX(hbox2), csc, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox2), entrycsc, TRUE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(hbox2), button2, FALSE, FALSE, 0);

    GtkWidget *cp = gtk_label_new("CP");
    GtkWidget *entrycp = gtk_entry_new();
    GtkWidget *button3 = gtk_button_new_with_label("Browse");
    gtk_entry_set_tabs(GTK_ENTRY(entrycp), FALSE);
    gtk_widget_set_hexpand(entrycp, TRUE);
    gtk_box_pack_start(GTK_BOX(hbox3), cp, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox3), entrycp, TRUE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(hbox3), button3, FALSE, FALSE, 0);

    GtkWidget *home = gtk_label_new("HOME");
    GtkWidget *entryhome = gtk_entry_new();
    GtkWidget *button4 = gtk_button_new_with_label("Browse");
    gtk_entry_set_tabs(GTK_ENTRY(entryhome), FALSE);
    gtk_widget_set_hexpand(entryhome, TRUE);
    gtk_box_pack_start(GTK_BOX(hbox4), home, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox4), entryhome, TRUE, TRUE, 3);
    gtk_box_pack_start(GTK_BOX(hbox4), button4, FALSE, FALSE, 0);

    GtkWidget *title = gtk_label_new("Odin");
    gtk_label_set_xalign(GTK_LABEL(title), 0.0);
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_size(font_desc, 20 * PANGO_SCALE);
    gtk_widget_override_font(title, font_desc);
    gtk_widget_set_margin_start(title, 10);
    pango_font_description_free(font_desc);


    gtk_box_pack_start(GTK_BOX(vbox), title, FALSE, FALSE, 0);
    int *hboxes[5] = {hbox, hbox1, hbox2, hbox3, hbox4};
    for(int i = 0; i < 5; i++) {
        gtk_box_pack_start(GTK_BOX(vbox), hboxes[i], FALSE, FALSE, 0);
    }

    g_signal_connect(button, "clicked", G_CALLBACK(browse_button_clicked), entryap);
    g_signal_connect(button1, "clicked", G_CALLBACK(browse_button_clicked), entrybl);
    g_signal_connect(button2, "clicked", G_CALLBACK(browse_button_clicked), entrycsc);
    g_signal_connect(button3, "clicked", G_CALLBACK(browse_button_clicked), entrycp);
    g_signal_connect(button4, "clicked", G_CALLBACK(browse_button_clicked), entryhome);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
