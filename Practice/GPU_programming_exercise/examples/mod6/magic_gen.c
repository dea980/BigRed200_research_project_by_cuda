// magic item generator
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

char *weaponList[] = {
    "sword",
    "spear",
    "dagger",
    "axe",
    "halbard"
};

char *passengerList[20] = {
    "Mr. Brown",
    "Mr. Black",
    "Mrs. Brown"
};

# 2-3-2 plaine layout
#   A B - C D E - F G
# 1       P   P         
# 2   P     P        
# 3                 


printf("Passenger %d - %s", i, passengerList[i]);

int seats[20][6];

char *adjs[] = {
    "shimmering",
    "silver",
    "gold",
    "rainbow"
};

char *damage_type[] = {
    "fire",
    "ice",
    "lightening", 
    "impact"
};

void generate_weapon(char **weapon);

int main(void) {
    char *myWeapon[3] = {};
    srand(time(0));
    generate_weapon(myWeapon);
    

    printf("You now have a  %s %s of %s\n", *(myWeapon + 1), *myWeapon, *(myWeapon +2));
    printf("You now have a  %s %s of %s\n", myWeapon[1], myWeapon[0], myWeapon[2]);
}

void generate_weapon(char **weapon) {
    // srand(time(0));
    int rNum = rand() % 5;
    printf("Random weapon: %s  %p\n", weaponList[rNum], weaponList + rNum);
    *weapon = *(weaponList + rNum);
    *(weapon + 1) = *(adjs + (rand() %  4));
    *(weapon + 2) = *(damage_type + (rand() % 4));
}
