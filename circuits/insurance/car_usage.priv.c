#include <stdint.h>

/**
 * Tarif based on location
 * @param INPUT_A_parkingspace: where is the car parked most of the time
 * (0: garage, 1: carport, 2: street/other
 * @param INPUT_B_car_usage: for which intention is the car used  
 * (0: private, 1: business)
 * @return tarif fraction depending on the traffic
*/
uint8_t mpc_main(uint8_t INPUT_A_parkingspace, uint8_t INPUT_A_carusage) {
    uint8_t price = 0;

    switch (INPUT_A_parkingspace) {
        case 0: price = 5;
            break;
        case 1: price = 15;
            break;
        case 2: price = 30;
    }
    if (INPUT_A_carusage) {
        price += 25;
    } else {
        price += 5;
    }

    return price;
}
