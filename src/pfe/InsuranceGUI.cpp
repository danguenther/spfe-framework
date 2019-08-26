#include "InsuranceGUI.hpp"
#include <cmath>

using namespace std;

// vector containing output bits
std::vector<uint32_t> InsuranceGUI::bit_input_vector;

/**
 * Funktionality for a new choice of dropdown menu 1 on page 1
  * @param widget combobox 1 on page 1
 * @param data comboboxes 2,3,4 on page 1
 */
void InsuranceGUI::on_cbox_1_1_change(GtkWidget *widget, GtkWidget *data[]) {
    int combobox_counter = 0;
    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 1
    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

        // User chose Opel
        case 0:

            // clear dropdown boxes 2-4 (reset further choices)
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[0]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

            // Fill second dropdown box
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_1", "Opel Corsa");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_2", "Opel Ampera");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_3", "Opel Insignia");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_4", "Opel Zafira");
            break;

            // User chose Audi
        case 1:

            // clear dropdown boxes 2-4 (reset further choices)
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[0]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

            // Fill second dropdown box
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_5", "Audi A1");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_6", "Audi TT");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_7", "Audi Q5");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_8", "Audi A8");
            break;

            // User chose Mercedes
        case 2:

            // clear dropdown boxes 2-4 (reset further choices)
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[0]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

            // Fill second dropdown box
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_9", "Mercedes A");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_10", "Mercedes E");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_11", "Mercedes CLS");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_12", "Mercedes S");
            break;

            // User chose Jaguar
        case 3:

            // clear dropdown boxes 2-4 (reset further choices)
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[0]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

            // Fill second dropdown box
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_13", "Jaguar e-pace");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_14", "Jaguar F-Type");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_15", "Jaguar i-pace");
            combobox_counter++;
            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[0]), combobox_counter, "CBOX1_2_16", "Jaguar xj");
            break;
    }

}

/**
 * Funktionality for a new choice of dropdown menu 2 on page 1
  * @param widget combobox 2 on page 1
 * @param data comboboxes 1,3,4 on page 1
 */
void InsuranceGUI::on_cbox_1_2_change(GtkWidget *widget, GtkWidget *data[]) {
    int combobox_counter = 0;

    // Which choice is active in dropdown box 1
    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(data[0]))) {
        case 0:

            // Fill next dropdown boxes with values dependent on user's choice of dropdown box 2
            switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {
                case 0:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_1", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_2", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_3", "Gas");
                    break;

                case 1:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_5", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_6", "Electro");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_7", "Hybrid");
                    break;

                case 2:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_9", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_10", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_11", "Gas");
                    break;

                case 3:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_13", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_14", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_15", "Gas");
                    break;
            }
            break;

        case 1:

            // Fill next dropdown boxes with values dependent on user's choice of dropdown box 2
            switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                case 0:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_1", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_2", "Diesel");
                    break;

                case 1:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_5", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_6", "Diesel");
                    break;

                case 2:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_9", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_10", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_11", "Electro");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_12", "Hybrid");
                    break;

                case 3:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_13", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_14", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_15", "Electro");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_16", "Hybrid");
                    break;
            }
            break;

        case 2:

            // Fill next dropdown boxes with values dependent on user's choice of dropdown box 2
            switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                case 0:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_1", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_2", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_2", "Electro");
                    break;

                case 1:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_5", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_6", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_2", "Electro");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_2", "Hybrid");
                    break;

                case 2:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_9", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_10", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_11", "Electro");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_12", "Hybrid");
                    break;

                case 3:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_13", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_14", "Diesel");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_15", "Electro");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_16", "Hybrid");
                    break;
            }
            break;

        case 3:

            // Fill next dropdown boxes with values dependent on user's choice of dropdown box 2
            switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                case 0:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_1", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_2", "Diesel");
                    break;

                case 1:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_5", "Petrol");
                    break;

                case 2:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_11", "Electro");
                    break;

                case 3:

                    // clear dropdown boxes 3-4 (reset further choices)
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[1]));
                    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                    // Fill third dropdown box
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_13", "Petrol");
                    combobox_counter++;
                    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[1]), combobox_counter, "CBOX1_3_14", "Diesel");
                    break;
            }
            break;
    }

}

/**
 * Funktionality for a new choice of dropdown menu 3 on page 1
  * @param widget combobox 3 on page 1
 * @param data comboboxes 1,2,4 on page 1
 */
void InsuranceGUI::on_cbox_1_3_change(GtkWidget *widget, GtkWidget *data[]) {
    int combobox_counter = 0;

    // Which choice is active in dropdown box 1
    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(data[0]))) {

        case 0:

            // Which choice is active in dropdown box 2
            switch (gtk_combo_box_get_active(GTK_COMBO_BOX(data[1]))) {

                case 0:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Corsa 65PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Corsa 75PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Corsa 90PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Corsa 150PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Corsa 75PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Corsa 95PS, Diesel");
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Corsa 90PS, Gas");
                            break;
                    }
                    break;

                case 1:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Ampera 54PS, Petrol");
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Ampera 54PS, Electro");
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Ampera 54PS, Hybrid");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Ampera 75PS, Hybrid");
                            break;
                    }
                    break;

                case 2:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 140PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 165PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 200PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 325PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 110PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 136PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 170PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 209PS, Diesel");
                            combobox_counter++;
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 140PS, Gas");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Insignia 220PS, Gas");
                            break;
                    }
                    break;
                case 3:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 120PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 140PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 170PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 200PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 120PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 131PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 136PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 170PS, Diesel");
                            combobox_counter++;
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 140PS, Gas");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Opel Zafira 150PS, Gas");
                            break;
                    }
                    break;
            }
            break;

        case 1:

            // Which choice is active in dropdown box 2
            switch (gtk_combo_box_get_active(GTK_COMBO_BOX(data[1]))) {

                case 0:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A1 82PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A1 116PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A1 150PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A1 200PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A1 90PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A1 116PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A1 136PS, Diesel");
                            break;
                    }
                    break;

                case 1:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi TT 179PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi TT 230PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi TT 245PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi TT 310PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi TT 184PS, Diesel");
                            break;
                    }
                    break;

                case 2:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:
                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 245PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 249PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 252PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 354PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 136PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 150PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 190PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 250PS, Diesel");
                            combobox_counter++;
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 245PS, Electro");
                            break;

                        case 3:
                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi Q5 245PS, Hybrid");
                            break;
                    }
                    break;

                case 3:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 252PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 340PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 500PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 605PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 211PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 286PS, Diesel");
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 286PS, Electro");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 340PS, Electro");
                            break;

                        case 3:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 286PS, Hybrid");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Audi A8 340PS, Hybrid");
                            break;
                    }
                    break;
            }
            break;

        case 2:

            // Which choice is active in dropdown box 2
            switch (gtk_combo_box_get_active(GTK_COMBO_BOX(data[1]))) {

                case 0:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 102PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 136PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 190PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 224PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 90PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 116PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 136PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 177PS, Diesel");
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes A 68PS, Electro");
                            combobox_counter++;
                    }
                    break;

                case 1:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 156PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 184PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 211PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 292PS, Petrol");
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 150PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 160PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 204PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 265PS, Diesel");
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 194PS, Electro");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 211PS, Electro");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 299PS, Electro");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 435PS, Electro");
                            break;

                        case 3:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 194PS, Hybrid");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 211PS, Hybrid");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 299PS, Hybrid");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes E 435PS, Hybrid");
                            break;
                    }
                    break;

                case 2:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 299PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 333PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 367PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 435PS, Petrol");
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 163PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 245PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 286PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 340PS, Diesel");
                            combobox_counter++;
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 299PS, Electro");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 367PS, Electro");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 435PS, Electro");
                            break;

                        case 3:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 299PS, Hybrid");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 367PS, Hybrid");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes CLS 435PS, Hybrid");
                            break;
                    }
                    break;

                case 3:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 272PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 435PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 530PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 630PS, Petrol");
                            combobox_counter++;
                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 252PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 286PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 340PS, Diesel");
                            break;

                        case 2:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 367PS, Electro");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 435PS, Electro");
                            break;

                        case 3:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 367PS, Hybrid");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Mercedes S 435PS, Hybrid");
                            break;
                    }
                    break;
            }
            break;

        case 3:

            // Which choice is active in dropdown box 2
            switch (gtk_combo_box_get_active(GTK_COMBO_BOX(data[1]))) {

                case 0:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar e-pace 200PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar e-pace 249PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar e-pace 300PS, Petrol");

                            break;

                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar e-pace 150PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar e-pace 179PS, Diesel");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar e-pace 241PS, Diesel");
                    }
                    break;

                case 1:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar F-Type 300PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar F-Type 381PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar F-Type 551PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar F-Type 575PS, Petrol");
                            break;
                    }
                    break;

                case 2:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar i-pace 234PS, Electro");
                            break;
                    }
                    break;

                case 3:

                    // Fill next dropdown boxes with values dependent on user's choice of dropdown box 3
                    switch (gtk_combo_box_get_active(GTK_COMBO_BOX(widget))) {

                        case 0:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar xj 241PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar xj 385PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar xj 470PS, Petrol");
                            combobox_counter++;
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar xj 575PS, Petrol");
                            combobox_counter++;
                            break;
                        case 1:

                            // clear dropdown boxes 4 (reset further choice)
                            gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data[2]));

                            // Fill fourth dropdown box
                            gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(data[2]),
                                                      combobox_counter,
                                                      "CBOX1_3_13",
                                                      "Jaguar xj 300PS, Diesel");
                            break;
                    }
                    break;
            }
            break;

            break;
    }
}

/**
 * Converts an 32-bit value to a vector containing the bits to represent the value as single values
  * @param bitrange number of bits required for the represented value
 * @param ref_value value to convert
 */
void InsuranceGUI::convert_int_to_bit(uint8_t bitrange, uint32_t ref_value) {

    uint32_t temp = 0, value = 0;

    for (int i = bitrange - 1; i >= 0; i--) {

        temp = pow(2, i);

        // 2^i contained in ref_value - push 1
        if (ref_value >= temp) {

            ref_value -= pow(2, i);

            InsuranceGUI::bit_input_vector.push_back(1);

            // 2^i not contained in ref_value - push 0
        } else {

            InsuranceGUI::bit_input_vector.push_back(0);

        }

    }

}

/**
 * Converts a vector containing bits into an 32-bit integer
  * @param bit_vector vector of bits to convert
  * @return returns float value represented by vector
 */
uint32_t InsuranceGUI::convert_bit_to_int(std::vector<uint32_t> bit_vector) {

    uint32_t temp = 0, result = 0;

    // Go through the bit vector
    for (int i = bit_vector.size() - 1; i >= 0; i--) {

        temp = pow(2, (bit_vector.size() - 1 - i));

        if (bit_vector[i] == 1) {
            result += temp;
        }

    }

    return (result >> FIXEDPOINT_FRACTION_BITS);
}

/**
 * Displays next page of the Client Form
  * @param widget pressed button
  * @param data nothing
 */
void InsuranceGUI::continue_button_clicked(GtkWidget *widget, gpointer data) {

    // Next page
    gtk_notebook_next_page(GTK_NOTEBOOK(data));

}

/**
 * Displays previous page of the Client Form
  * @param widget pressed button
  * @param data nothing
 */
void InsuranceGUI::back_button_clicked(GtkWidget *widget, gpointer data) {

    // Previous page
    gtk_notebook_prev_page(GTK_NOTEBOOK(data));

}

/**
 * Functionlity when the client form's finish button is pressed
  * @param widget pressed button
  * @param data contains main window itself and Inputs to the Client Form
 */
void InsuranceGUI::finish_button_clicked(GtkWidget *widget, GtkWidget *data[]) {

    // Close main window doesnt work
    gtk_main_quit();

    gint number = 0;

    // Read Inputs
    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[0]));
    convert_int_to_bit(8, number);

    number = (gtk_combo_box_get_active(GTK_COMBO_BOX(data[1])) + 1) * 100 +
        (gtk_combo_box_get_active(GTK_COMBO_BOX(data[2])) + 1) * 10 +
        (gtk_combo_box_get_active(GTK_COMBO_BOX(data[3])) + 1);
    convert_int_to_bit(16, number);

    for (int i = 4; i < 7; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[7]));
    convert_int_to_bit(8, number);

    for (int i = 8; i < 9; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[9]));
    convert_int_to_bit(8, number);

    for (int i = 10; i < 12; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[12]));
    convert_int_to_bit(8, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[13])));
    convert_int_to_bit(16, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[14])));
    convert_int_to_bit(8, number);

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[15]));
    convert_int_to_bit(8, number);

    for (int i = 16; i < 17; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(16, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[17]));
    convert_int_to_bit(8, number);

    for (int i = 18; i < 19; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[19]));
    convert_int_to_bit(8, number);

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[20]));
    convert_int_to_bit(8, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[21])));
    convert_int_to_bit(8, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[22])));
    convert_int_to_bit(16, number);

    for (int i = 23; i < 25; i++) {
        number = atoi(gtk_entry_get_text(GTK_ENTRY(data[i])));
        convert_int_to_bit(8, number);
    }

    number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[25]));
    convert_int_to_bit(8, number);

    number = atoi(gtk_entry_get_text(GTK_ENTRY(data[26])));
    convert_int_to_bit(16, number);

    for (int i = 27; i < 34; i++) {
        number = gtk_combo_box_get_active(GTK_COMBO_BOX(data[i]));
        convert_int_to_bit(8, number);
    }

}

/**
 * Creates the GUI for the Client Form
  * @param argc execute parameter
  * @param argv execute parameter
 */
void InsuranceGUI::createGUI(int argc, char *argv[]) {

    // Initialize gtk
    gtk_init(&argc, &argv);

    // Declaration
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // Notebook
    GtkWidget *notebook;

    // Tab Vboxes
    GtkWidget *tab_vbox_1, *tab_vbox_2, *tab_vbox_3, *tab_vbox_4, *tab_vbox_5, *tab_vbox_6, *tab_vbox_7, *tab_vbox_8,
        *tab_vbox_9;

    // Tab Hboxes
    GtkWidget *tab_hbox_1, *tab_hbox_2, *tab_hbox_3, *tab_hbox_4, *tab_hbox_5, *tab_hbox_6, *tab_hbox_7, *tab_hbox_8,
        *tab_hbox_9;

    // Tab textfields
    GtkWidget *tab_entry_1_1, *tab_entry_1_2, *tab_entry_2_1, *tab_entry_2_2, *tab_entry_2_3, *tab_entry_3_1,
        *tab_entry_3_2, *tab_entry_3_3, *tab_entry_3_4, *tab_entry_4_1, *tab_entry_5_1, *tab_entry_6_1, *tab_entry_7_1,
        *tab_entry_7_2, *tab_entry_7_3, *tab_entry_7_4, *tab_entry_7_5;

    // Tab dropdown comboboxes
    GtkWidget *tab_cbox_1_1, *tab_cbox_1_2, *tab_cbox_1_3, *tab_cbox_1_4, *tab_cbox_2_1, *tab_cbox_2_2, *tab_cbox_3_1,
        *tab_cbox_3_2, *tab_cbox_4_1, *tab_cbox_6_1, *tab_cbox_6_2, *tab_cbox_7_1, *tab_cbox_8_1, *tab_cbox_8_2,
        *tab_cbox_9_1, *tab_cbox_9_2, *tab_cbox_9_3, *tab_cbox_9_4, *tab_cbox_9_5;

    // Tab question labels
    GtkWidget *tab_qlabel_1_1, *tab_qlabel_1_2, *tab_qlabel_1_3, *tab_qlabel_1_4, *tab_qlabel_1_5, *tab_qlabel_1_6,
        *tab_qlabel_2_1, *tab_qlabel_2_2, *tab_qlabel_2_3, *tab_qlabel_2_4, *tab_qlabel_2_5, *tab_qlabel_3_1,
        *tab_qlabel_3_2, *tab_qlabel_3_3, *tab_qlabel_3_4, *tab_qlabel_3_5, *tab_qlabel_3_6, *tab_qlabel_3_7,
        *tab_qlabel_3_8, *tab_qlabel_3_9, *tab_qlabel_4_1, *tab_qlabel_5_1, *tab_qlabel_6_1, *tab_qlabel_6_2,
        *tab_qlabel_7_1, *tab_qlabel_7_2, *tab_qlabel_7_3, *tab_qlabel_7_4, *tab_qlabel_7_5, *tab_qlabel_7_6,
        *tab_qlabel_8_1, *tab_qlabel_8_2, *tab_qlabel_9_1, *tab_qlabel_9_2, *tab_qlabel_9_3, *tab_qlabel_9_4,
        *tab_qlabel_9_5;

    // Tab name labels
    GtkWidget *tab_label_1, *tab_label_2, *tab_label_3, *tab_label_4, *tab_label_5, *tab_label_6, *tab_label_7,
        *tab_label_8, *tab_label_9;

    // Tab continue buttons
    GtkWidget *tab_continue_button_1, *tab_continue_button_2, *tab_continue_button_3, *tab_continue_button_4,
        *tab_continue_button_5, *tab_continue_button_6, *tab_continue_button_7, *tab_continue_button_8;

    // Tab back buttons
    GtkWidget *tab_back_button_2, *tab_back_button_3, *tab_back_button_4, *tab_back_button_5, *tab_back_button_6,
        *tab_back_button_7, *tab_back_button_8, *tab_back_button_9;

    // Tab finish button
    GtkWidget *tab_finish_button;

    // GTK fields to read
    GtkWidget *fields_to_read[34], *cboxes_0[3], *cboxes_1[3], *cboxes_2[3];

    // Item counter for combobox 1
    int combobox_counter;



    // Initialize notebook
    notebook = gtk_notebook_new();
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_TOP);
    gtk_notebook_set_scrollable(GTK_NOTEBOOK(notebook), TRUE);

    // Connect close button to the window
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    // Page 1 (Information about the car)

    // Initialize boxes
    tab_vbox_1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    tab_cbox_1_1 = gtk_combo_box_text_new();
    tab_cbox_1_2 = gtk_combo_box_text_new();
    tab_cbox_1_3 = gtk_combo_box_text_new();
    tab_cbox_1_4 = gtk_combo_box_text_new();

    // Initialize question labels and align them
    tab_qlabel_1_1 = gtk_label_new("Which manufacturer produced your car?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_1_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_1_1), 0);
    tab_qlabel_1_2 = gtk_label_new("Which model is your car?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_1_2), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_1_2), 0);
    tab_qlabel_1_3 = gtk_label_new("Which fuel type does your car use?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_1_3), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_1_3), 0);
    tab_qlabel_1_4 = gtk_label_new("Which is your car?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_1_4), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_1_4), 0);
    tab_qlabel_1_5 = gtk_label_new("When was your car first licensed?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_1_5), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_1_5), 0);
    tab_qlabel_1_6 = gtk_label_new("When did you license your car?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_1_6), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_1_6), 0);

    // Initialize drop down boxes
    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_1_1), combobox_counter, "CBOX1_1_1", "Opel");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_1_1), combobox_counter, "CBOX1_1_2", "Audi");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_1_1), combobox_counter, "CBOX1_1_3", "Mercedes");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_1_1), combobox_counter, "CBOX1_1_4", "Jaguar");
    combobox_counter++;

    // Initialize text fields
    tab_entry_1_1 = gtk_entry_new();
    tab_entry_1_2 = gtk_entry_new();

    // Initialize tab name
    tab_label_1 = gtk_label_new("Page 1");

    // Initialize Widget Arrays for dropdown menu functionality
    // Box 1 changed
    cboxes_0[0] = tab_cbox_1_2;
    cboxes_0[1] = tab_cbox_1_3;
    cboxes_0[2] = tab_cbox_1_4;
    // Box 2 changed
    cboxes_1[0] = tab_cbox_1_1;
    cboxes_1[1] = tab_cbox_1_3;
    cboxes_1[2] = tab_cbox_1_4;
    // Box 3 changed
    cboxes_2[0] = tab_cbox_1_1;
    cboxes_2[1] = tab_cbox_1_2;
    cboxes_2[2] = tab_cbox_1_4;

    // Initialize buttons
    tab_continue_button_1 = gtk_button_new_with_label("Continue");

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_1), tab_continue_button_1, 0, 0, 0);

    // Pack the vbox
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_qlabel_1_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_cbox_1_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_qlabel_1_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_cbox_1_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_qlabel_1_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_cbox_1_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_qlabel_1_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_cbox_1_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_qlabel_1_5, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_entry_1_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_qlabel_1_6, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_entry_1_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_1), tab_hbox_1, 0, 0, 0);

    // First combobox changed functionality
    g_signal_connect(GTK_COMBO_BOX(tab_cbox_1_1), "changed", G_CALLBACK(on_cbox_1_1_change), cboxes_0);
    // Second combobox changed functionality
    g_signal_connect(GTK_COMBO_BOX(tab_cbox_1_2), "changed", G_CALLBACK(on_cbox_1_2_change), cboxes_1);
    // Third combobox changed functionality
    g_signal_connect(GTK_COMBO_BOX(tab_cbox_1_3), "changed", G_CALLBACK(on_cbox_1_3_change), cboxes_2);

    // Connect button functionality
    g_signal_connect(tab_continue_button_1, "clicked", G_CALLBACK(continue_button_clicked), notebook);

    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_1, tab_label_1);

    // Page 2 (Personal information)

    // Initialize boxes
    tab_vbox_2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Initialize question labels and align them
    tab_qlabel_2_1 = gtk_label_new("How old are you?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_2_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_2_1), 0);
    //
    tab_qlabel_2_2 = gtk_label_new("Who holds the policy?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_2_2), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_2_2), 0);
    //
    tab_qlabel_2_3 = gtk_label_new("How long do you have your driving license?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_2_3), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_2_3), 0);
    //
    tab_qlabel_2_4 = gtk_label_new("What is your job?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_2_4), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_2_4), 0);
    //
    tab_qlabel_2_5 = gtk_label_new("How many drivers are under 25 and will drive this car?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_2_5), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_2_5), 0);

    // Initialize text fields
    tab_entry_2_1 = gtk_entry_new();
    tab_entry_2_2 = gtk_entry_new();
    tab_entry_2_3 = gtk_entry_new();
    tab_cbox_2_1 = gtk_combo_box_text_new();
    tab_cbox_2_2 = gtk_combo_box_text_new();

    combobox_counter = 0;

    // Initialize dropdown menus
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_1), combobox_counter, "CBOX2_1_1", "Insurance Taker");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_1), combobox_counter, "CBOX2_1_2", "Spouse");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_1), combobox_counter, "CBOX2_1_3", "Child");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_1), combobox_counter, "CBOX2_1_4", "Loaner");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_1), combobox_counter, "CBOX2_1_5", "Lessor");

    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_2), combobox_counter, "CBOX2_2_1", "Unemployed");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_2), combobox_counter, "CBOX2_2_2", "Farmer");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_2), combobox_counter, "CBOX2_2_3", "Independent Worker");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_2), combobox_counter, "CBOX2_2_4", "Employee");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_2_2), combobox_counter, "CBOX2_2_5", "Official");

    // Initialize tab name
    tab_label_2 = gtk_label_new("Page 2");

    // Initialize buttons
    tab_continue_button_2 = gtk_button_new_with_label("Continue");
    tab_back_button_2 = gtk_button_new_with_label("Back");

    // Connect button functionality
    g_signal_connect(tab_continue_button_2, "clicked", G_CALLBACK(continue_button_clicked), notebook);
    g_signal_connect(tab_back_button_2, "clicked", G_CALLBACK(back_button_clicked), notebook);

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_2), tab_back_button_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_hbox_2), tab_continue_button_2, 0, 0, 0);

    // Pack the vbox
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_qlabel_2_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_entry_2_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_qlabel_2_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_cbox_2_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_qlabel_2_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_entry_2_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_qlabel_2_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_cbox_2_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_qlabel_2_5, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_entry_2_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_2), tab_hbox_2, 0, 0, 0);

    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_2, tab_label_2);

    // Page 3 (Prior Damages)

    // Initialize box
    tab_vbox_3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    tab_cbox_3_1 = gtk_combo_box_text_new();
    tab_cbox_3_2 = gtk_combo_box_text_new();

    // Initialize question labels and align them
    tab_qlabel_3_1 = gtk_label_new("Specify the last two accidents you had");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_1), 0);
    tab_qlabel_3_2 = gtk_label_new("Damage 1");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_2), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_2), 0);
    tab_qlabel_3_3 = gtk_label_new("How many years ago did the accident happen?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_3), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_3), 0);
    tab_qlabel_3_4 = gtk_label_new("What was your insurance to that time?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_4), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_4), 0);
    tab_qlabel_3_5 = gtk_label_new("How much did it cost?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_5), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_5), 0);
    tab_qlabel_3_6 = gtk_label_new("Damage 2");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_6), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_6), 0);
    tab_qlabel_3_7 = gtk_label_new("How many years ago did the accident happen?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_7), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_7), 0);
    tab_qlabel_3_8 = gtk_label_new("What was your insurance to that time?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_8), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_8), 0);
    tab_qlabel_3_9 = gtk_label_new("How much did it cost?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_3_9), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_3_9), 0);

    combobox_counter = 0;

    // Initialize drop down menus
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_3_1), combobox_counter, "CBOX3_1_1", "no insurance");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_3_1), combobox_counter, "CBOX3_1_2", "Haftpflicht");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_3_1), combobox_counter, "CBOX3_1_3", "Teilkasko");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_3_1), combobox_counter, "CBOX3_1_4", "Vollkasko");

    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_3_2), combobox_counter, "CBOX3_2_1", "no insurance");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_3_2), combobox_counter, "CBOX3_2_2", "Haftpflicht");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_3_2), combobox_counter, "CBOX3_2_3", "Teilkasko");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_3_2), combobox_counter, "CBOX3_2_4", "Vollkasko");

    // Initialize text fields
    tab_entry_3_1 = gtk_entry_new();
    tab_entry_3_2 = gtk_entry_new();
    tab_entry_3_3 = gtk_entry_new();
    tab_entry_3_4 = gtk_entry_new();

    // Initialize tab name
    tab_label_3 = gtk_label_new("Page 3");

    // Initialize buttons
    tab_continue_button_3 = gtk_button_new_with_label("Continue");
    tab_back_button_3 = gtk_button_new_with_label("Back");

    // Connect button functionality
    g_signal_connect(tab_continue_button_3, "clicked", G_CALLBACK(continue_button_clicked), notebook);
    g_signal_connect(tab_back_button_3, "clicked", G_CALLBACK(back_button_clicked), notebook);

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_3), tab_back_button_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_hbox_3), tab_continue_button_3, 0, 0, 0);

    // Pack the vbox
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_entry_3_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_cbox_3_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_5, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_entry_3_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_6, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_7, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_entry_3_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_8, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_cbox_3_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_qlabel_3_9, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_entry_3_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_3), tab_hbox_3, 0, 0, 0);

    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_3, tab_label_3);

    // Page 4 (Information about the location)

    // Initialize box
    tab_vbox_4 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Initialize question labels and align them
    tab_qlabel_4_1 = gtk_label_new("How is the population in your town?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_4_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_4_1), 0);

    // Initialize dropdown menu
    tab_cbox_4_1 = gtk_combo_box_text_new();

    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_4_1), combobox_counter, "CBOX4_1_1", "Low");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_4_1), combobox_counter, "CBOX4_1_2", "Medium");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_4_1), combobox_counter, "CBOX4_1_3", "High");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_4_1), combobox_counter, "CBOX4_1_4", "Very High");

    // Initialize tab name
    tab_label_4 = gtk_label_new("Page 4");

    // Initialize buttons
    tab_continue_button_4 = gtk_button_new_with_label("Continue");
    tab_back_button_4 = gtk_button_new_with_label("Back");

    // Connect button functionality
    g_signal_connect(tab_continue_button_4, "clicked", G_CALLBACK(continue_button_clicked), notebook);
    g_signal_connect(tab_back_button_4, "clicked", G_CALLBACK(back_button_clicked), notebook);

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_4), tab_back_button_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_hbox_4), tab_continue_button_4, 0, 0, 0);

    // Pack the box
    gtk_box_pack_start(GTK_BOX(tab_vbox_4), tab_qlabel_4_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_4), tab_cbox_4_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_4), tab_hbox_4, 0, 0, 0);

    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_4, tab_label_4);

    // Page 5 (Points in flensburg)

    // Initialize box
    tab_vbox_5 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_5 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Initialize question labels and align them
    tab_qlabel_5_1 = gtk_label_new("How many points do you have in Flensburg?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_5_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_5_1), 0);

    // Initialize text fields
    tab_entry_5_1 = gtk_entry_new();

    // Initialize tab name
    tab_label_5 = gtk_label_new("Page 5");

    // Initialize buttons
    tab_continue_button_5 = gtk_button_new_with_label("Continue");
    tab_back_button_5 = gtk_button_new_with_label("Back");

    // Connect button functionality
    g_signal_connect(tab_continue_button_5, "clicked", G_CALLBACK(continue_button_clicked), notebook);
    g_signal_connect(tab_back_button_5, "clicked", G_CALLBACK(back_button_clicked), notebook);

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_5), tab_back_button_5, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_hbox_5), tab_continue_button_5, 0, 0, 0);

    // Pack the box
    gtk_box_pack_start(GTK_BOX(tab_vbox_5), tab_qlabel_5_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_5), tab_entry_5_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_5), tab_hbox_5, 0, 0, 0);

    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_5, tab_label_5);

    // Page 6 (Car usage)

    // Initialize box
    tab_vbox_6 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_6 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Initialize question labels and align them
    tab_qlabel_6_1 = gtk_label_new("Where do you park your car normally?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_6_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_6_1), 0);
    //
    tab_qlabel_6_2 = gtk_label_new("Is the car used for business or private use?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_6_2), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_6_2), 0);

    // Initialize text fields
    tab_cbox_6_1 = gtk_combo_box_text_new();

    combobox_counter = 0;

    // Initialize dropdown menus
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_6_1), combobox_counter, "CBOX6_1_1", "Garage");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_6_1), combobox_counter, "CBOX6_1_2", "Carport");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_6_1), combobox_counter, "CBOX6_1_3", "Street/Other");

    tab_cbox_6_2 = gtk_combo_box_text_new();
    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_6_2), combobox_counter, "CBOX6_2_1", "Private");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_6_2), combobox_counter, "CBOX6_2_2", "Business");


    // Initialize tab name
    tab_label_6 = gtk_label_new("Page 6");

    // Initialize buttons
    tab_continue_button_6 = gtk_button_new_with_label("Continue");
    tab_back_button_6 = gtk_button_new_with_label("Back");

    // Connect button functionality
    g_signal_connect(tab_continue_button_6, "clicked", G_CALLBACK(continue_button_clicked), notebook);
    g_signal_connect(tab_back_button_6, "clicked", G_CALLBACK(back_button_clicked), notebook);

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_6), tab_back_button_6, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_hbox_6), tab_continue_button_6, 0, 0, 0);


    // Pack the box
    gtk_box_pack_start(GTK_BOX(tab_vbox_6), tab_qlabel_6_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_6), tab_cbox_6_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_6), tab_qlabel_6_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_6), tab_cbox_6_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_6), tab_hbox_6, 0, 0, 0);

    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_6, tab_label_6);

    // Page 7 (Insurance scope)

    // Initialize box
    tab_vbox_7 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_7 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Initialize question labels and align them
    tab_qlabel_7_1 = gtk_label_new("How many months in the year do you need the insurance?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_7_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_7_1), 0);
    //
    tab_qlabel_7_2 = gtk_label_new("How many kilometers are you driving per year?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_7_2), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_7_2), 0);
    //
    tab_qlabel_7_3 = gtk_label_new("Damagefreeclass for a Haftpflicht insurance?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_7_3), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_7_3), 0);
    //
    tab_qlabel_7_4 = gtk_label_new("Damagefreeclass for a Kasko insurance?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_7_4), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_7_4), 0);
    //
    tab_qlabel_7_5 = gtk_label_new("Do want to be insured Haftpflicht, Teilkasko or Vollkasko?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_7_5), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_7_5), 0);
    //
    tab_qlabel_7_6 = gtk_label_new("How much is the selfpart u take in every accident?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_7_6), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_7_6), 0);

    // Initialize text fields
    tab_entry_7_1 = gtk_entry_new();
    tab_entry_7_2 = gtk_entry_new();
    tab_entry_7_3 = gtk_entry_new();
    tab_entry_7_4 = gtk_entry_new();
    tab_entry_7_5 = gtk_entry_new();

    // Initialize dropdown menu
    tab_cbox_7_1 = gtk_combo_box_text_new();

    combobox_counter = 0;

    // Initialize dropdown menu
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_7_1), combobox_counter, "CBOX7_1_1", "Haftpflicht");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_7_1), combobox_counter, "CBOX7_1_2", "Teilkasko");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_7_1), combobox_counter, "CBOX7_1_3", "Vollkasko");


    // Initialize tab name
    tab_label_7 = gtk_label_new("Page 7");

    // Initialize buttons
    tab_continue_button_7 = gtk_button_new_with_label("Continue");
    tab_back_button_7 = gtk_button_new_with_label("Back");

    // Connect button functionality
    g_signal_connect(tab_continue_button_7, "clicked", G_CALLBACK(continue_button_clicked), notebook);
    g_signal_connect(tab_back_button_7, "clicked", G_CALLBACK(back_button_clicked), notebook);

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_7), tab_back_button_7, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_hbox_7), tab_continue_button_7, 0, 0, 0);

    // Pack the box
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_qlabel_7_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_entry_7_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_qlabel_7_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_entry_7_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_qlabel_7_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_entry_7_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_qlabel_7_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_entry_7_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_qlabel_7_5, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_cbox_7_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_qlabel_7_6, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_entry_7_5, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_7), tab_hbox_7, 0, 0, 0);

    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_7, tab_label_7);

    // Page 8 (Additional services)

    // Initialize box
    tab_vbox_8 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_8 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Initialize question labels and align them
    tab_qlabel_8_1 = gtk_label_new("Are you wishing an additional workshop choice?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_8_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_8_1), 0);
    //
    tab_qlabel_8_2 = gtk_label_new("Are you wishing your insurance to cover damages from martens?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_8_2), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_8_2), 0);

    // Initialize dropdown menu
    tab_cbox_8_1 = gtk_combo_box_text_new();

    combobox_counter = 0;

    // Initialize dropdown menus
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_8_1), combobox_counter, "CBOX8_1_1", "No");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_8_1), combobox_counter, "CBOX8_1_2", "Yes");

    tab_cbox_8_2 = gtk_combo_box_text_new();

    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_8_2), combobox_counter, "CBOX8_2_1", "No");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_8_2), combobox_counter, "CBOX8_2_2", "Yes");

    // Initialize tab name
    tab_label_8 = gtk_label_new("Page 8");

    // Initialize buttons
    tab_continue_button_8 = gtk_button_new_with_label("Continue");
    tab_back_button_8 = gtk_button_new_with_label("Back");

    // Connect button functionality
    g_signal_connect(tab_continue_button_8, "clicked", G_CALLBACK(continue_button_clicked), notebook);
    g_signal_connect(tab_back_button_8, "clicked", G_CALLBACK(back_button_clicked), notebook);

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_8), tab_back_button_8, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_hbox_8), tab_continue_button_8, 0, 0, 0);

    // Pack the box
    gtk_box_pack_start(GTK_BOX(tab_vbox_8), tab_qlabel_8_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_8), tab_cbox_8_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_8), tab_qlabel_8_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_8), tab_cbox_8_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_8), tab_hbox_8, 0, 0, 0);


    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_8, tab_label_8);

    // Page 9 (Additional information)

    // Initialize box
    tab_vbox_9 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    tab_hbox_9 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Initialize question labels and align them
    tab_qlabel_9_1 = gtk_label_new("In which time spacings do you wish to pay?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_9_1), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_9_1), 0);
    //
    tab_qlabel_9_2 = gtk_label_new("Are you a club member?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_9_2), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_9_2), 0);
    //
    tab_qlabel_9_3 = gtk_label_new("Do you have a ticket for public transport?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_9_3), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_9_3), 0);
    //
    tab_qlabel_9_4 = gtk_label_new("Do you have access to another car?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_9_4), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_9_4), 0);
    //
    tab_qlabel_9_5 = gtk_label_new("Do you want to have a protection letter?");
    gtk_label_set_xalign(GTK_LABEL(tab_qlabel_9_5), 0);
    gtk_label_set_yalign(GTK_LABEL(tab_qlabel_9_5), 0);

    // Initialize text fields
    tab_cbox_9_1 = gtk_combo_box_text_new();

    combobox_counter = 0;

    // Initialize dropdown menus
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_1), combobox_counter, "CBOX9_1_1", "yearly");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_1), combobox_counter, "CBOX9_1_2", "half-yearly");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_1), combobox_counter, "CBOX9_1_3", "quarterly");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_1), combobox_counter, "CBOX9_1_4", "monthly");

    tab_cbox_9_2 = gtk_combo_box_text_new();

    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_2), combobox_counter, "CBOX9_2_1", "No");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_2), combobox_counter, "CBOX9_2_2", "Yes");

    tab_cbox_9_3 = gtk_combo_box_text_new();

    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_3), combobox_counter, "CBOX9_3_1", "No");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_3), combobox_counter, "CBOX9_3_2", "Yes");

    tab_cbox_9_4 = gtk_combo_box_text_new();

    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_4), combobox_counter, "CBOX9_4_1", "No");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_4), combobox_counter, "CBOX9_4_2", "Yes");

    tab_cbox_9_5 = gtk_combo_box_text_new();

    combobox_counter = 0;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_5), combobox_counter, "CBOX9_5_1", "No");
    combobox_counter++;
    gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(tab_cbox_9_5), combobox_counter, "CBOX9_5_2", "Yes");

    // Initialize tab name
    tab_label_9 = gtk_label_new("Page 9");

    // Initialize buttons
    tab_finish_button = gtk_button_new_with_label("Finish");
    tab_back_button_9 = gtk_button_new_with_label("Back");

    // Initialize fields to read (INPUTS)
    fields_to_read[0] = tab_cbox_1_1;
    fields_to_read[1] = tab_cbox_1_2;
    fields_to_read[2] = tab_cbox_1_3;
    fields_to_read[3] = tab_cbox_1_4;
    fields_to_read[4] = tab_entry_1_1;
    fields_to_read[5] = tab_entry_1_2;
    fields_to_read[6] = tab_entry_2_1;
    fields_to_read[7] = tab_cbox_2_1;
    fields_to_read[8] = tab_entry_2_2;
    fields_to_read[9] = tab_cbox_2_2;
    fields_to_read[10] = tab_entry_2_3;
    fields_to_read[11] = tab_entry_3_1;
    fields_to_read[12] = tab_cbox_3_1;
    fields_to_read[13] = tab_entry_3_2;
    fields_to_read[14] = tab_entry_3_3;
    fields_to_read[15] = tab_cbox_3_2;
    fields_to_read[16] = tab_entry_3_4;
    fields_to_read[17] = tab_cbox_4_1;
    fields_to_read[18] = tab_entry_5_1;
    fields_to_read[19] = tab_cbox_6_1;
    fields_to_read[20] = tab_cbox_6_2;
    fields_to_read[21] = tab_entry_7_1;
    fields_to_read[22] = tab_entry_7_2;
    fields_to_read[23] = tab_entry_7_3;
    fields_to_read[24] = tab_entry_7_4;
    fields_to_read[25] = tab_cbox_7_1;
    fields_to_read[26] = tab_entry_7_5;
    fields_to_read[27] = tab_cbox_8_1;
    fields_to_read[28] = tab_cbox_8_2;
    fields_to_read[29] = tab_cbox_9_1;
    fields_to_read[30] = tab_cbox_9_2;
    fields_to_read[31] = tab_cbox_9_3;
    fields_to_read[32] = tab_cbox_9_4;
    fields_to_read[33] = tab_cbox_9_5;
    fields_to_read[34] = window;

    // Connect button functionality
    g_signal_connect(tab_finish_button, "clicked", G_CALLBACK(finish_button_clicked), fields_to_read);
    g_signal_connect(tab_back_button_9, "clicked", G_CALLBACK(back_button_clicked), notebook);

    // Pack the hbox
    gtk_box_pack_start(GTK_BOX(tab_hbox_9), tab_back_button_9, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_hbox_9), tab_finish_button, 0, 0, 0);

    // Pack the box
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_qlabel_9_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_cbox_9_1, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_qlabel_9_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_cbox_9_2, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_qlabel_9_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_cbox_9_3, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_qlabel_9_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_cbox_9_4, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_qlabel_9_5, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_cbox_9_5, 0, 0, 0);
    gtk_box_pack_start(GTK_BOX(tab_vbox_9), tab_hbox_9, 0, 0, 0);

    // Append the page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), tab_vbox_9, tab_label_9);


    // Set size of the window
    gtk_widget_set_size_request(window, 800, 400);

    // Set title of the window
    gtk_window_set_title(GTK_WINDOW(window), "Insurance Calculator");

    // Append notebook to window
    gtk_container_add(GTK_CONTAINER(window), notebook);

    // Show window and all its widgets
    gtk_widget_show_all(window);

    gtk_main();
}
