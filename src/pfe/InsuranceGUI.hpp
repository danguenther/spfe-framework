#include <gtk/gtk.h>
#include <string>
#include <vector>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
using namespace std;

#ifndef INSURANCEGUI_H
#define HEADER_H

/**
 * fraction bits of the fixed point representation
 */
#define FIXEDPOINT_FRACTION_BITS 16

class InsuranceGUI {

  public:

    static std::vector<uint32_t> bit_input_vector;

    static uint32_t convert_bit_to_int(std::vector<uint32_t> bit_vector);

    static void convert_int_to_bit(uint8_t bitrange, uint32_t ref_value);

    static void on_cbox_1_1_change(GtkWidget *widget, GtkWidget *data[]);

    static void on_cbox_1_2_change(GtkWidget *widget, GtkWidget *data[]);

    static void on_cbox_1_3_change(GtkWidget *widget, GtkWidget *data[]);

    static void continue_button_clicked(GtkWidget *widget, gpointer data);

    static void back_button_clicked(GtkWidget *widget, gpointer data);

    static void finish_button_clicked(GtkWidget *widget, GtkWidget *data[]);

    void createGUI(int argc, char *argv[]);

};
#endif
