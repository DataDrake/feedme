//
// Created by bryan on 6/10/16.
//

#include <gtk/gtk.h>

void addChoice(GtkListStore * store, char *icon_file, gchar *icon_name){
    GError * err = 0;
    GtkTreeIter iter;

    GdkPixbuf * a = gdk_pixbuf_new_from_file(icon_file,&err);
    a = gdk_pixbuf_scale_simple(a,64,64,GDK_INTERP_BILINEAR);
    gtk_list_store_append(store,&iter);
    gtk_list_store_set(store,&iter,0,a,1,icon_name,-1);
}

int main(int argc, char **argv) {

    GtkWindow *window;
    GtkBuilder *gtkBuilder;
    GtkListStore * feed_choices;
    GtkCellRendererPixbuf * pix;

    gtk_init(&argc,&argv);

    gtkBuilder = gtk_builder_new();
    gtk_builder_add_from_file(gtkBuilder,"feed-me-main.ui",NULL);
    gtk_builder_connect_signals ( gtkBuilder, NULL );

    window = GTK_WINDOW(gtk_builder_get_object(gtkBuilder,"window1"));
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    feed_choices = GTK_LIST_STORE(gtk_builder_get_object(gtkBuilder,"feed_choices"));
    pix = GTK_CELL_RENDERER_PIXBUF(gtk_builder_get_object(gtkBuilder,"cellrenderertext1"));
    g_object_set(G_OBJECT(pix),"stock-size",GTK_ICON_SIZE_MENU,NULL);

    addChoice(feed_choices,"anandtech.png","Anandtech");
    addChoice(feed_choices,"engadget.png","Engadget");
    addChoice(feed_choices,"wccftech.ico","WCCFTech");

    gtk_window_set_default_size(window,800,600);
    gtk_window_present(window);
    gtk_main();

    return 0;
}
