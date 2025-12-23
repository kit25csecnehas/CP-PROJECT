#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "vehicle.txt"

struct Vehicle {
    int id;
    char name[20];
    char number[20];
    float rentHour;
    float rentDay;
    int available;
};

struct Vehicle temp;
int tempAdded = 0;

/* Function Prototypes */
void addVehicle();
void saveVehicle();
void displayVehicles();
void rentVehicle();
void returnVehicle();

int main() {
    int choice;

    do {
        printf("\n==============================");
        printf("\n     VEHICLE RENTAL SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Vehicle (Output Only)");
        printf("\n2. Display Vehicles");
        printf("\n3. Save Last Added Vehicle");
        printf("\n4. Rent Vehicle");
        printf("\n5. Return Vehicle");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: displayVehicles(); break;
            case 3: saveVehicle(); break;
            case 4: rentVehicle(); break;
            case 5: returnVehicle(); break;
            case 6: printf("\nThank you!\n"); break;
            default: printf("\nInvalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

/* ADD VEHICLE (TEMPORARY) */
void addVehicle() {
    printf("\nEnter Vehicle ID: ");
    scanf("%d", &temp.id);

    printf("Enter Vehicle Name: ");
    scanf("%s", temp.name);

    printf("Enter Vehicle Number: ");
    scanf("%s", temp.number);

    printf("Enter Rent per Hour: ");
    scanf("%f", &temp.rentHour);

    printf("Enter Rent per Day: ");
    scanf("%f", &temp.rentDay);

    temp.available = 1;
    tempAdded = 1;

    printf("\nVehicle added temporarily (not saved to file).\n");
}

/* SAVE VEHICLE */
void saveVehicle() {
    FILE *fp;

    if (!tempAdded) {
        printf("\nNo new vehicle to save!\n");
        return;
    }

    fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("\nFile error!\n");
        return;
    }

    fprintf(fp, "%d %s %s %.0f %.0f %d\n",
            temp.id, temp.name, temp.number,
            temp.rentHour, temp.rentDay, temp.available);

    fclose(fp);
    tempAdded = 0;

    printf("\nVehicle saved to file successfully!\n");
}

/* DISPLAY VEHICLES */
void displayVehicles() {
    FILE *fp;
    struct Vehicle v;

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo vehicles found!\n");
        return;
    }

    printf("\nID   NAME     NUMBER        HOUR   DAY   STATUS");
    printf("\n-----------------------------------------------");

    while (fscanf(fp, "%d %s %s %f %f %d",
                  &v.id, v.name, v.number,
                  &v.rentHour, &v.rentDay, &v.available) != EOF) {

        printf("\n%-4d %-8s %-12s %-6.0f %-6.0f %s",
               v.id, v.name, v.number,
               v.rentHour, v.rentDay,
               v.available ? "Available" : "Rented");
    }

    fclose(fp);
}

/* RENT VEHICLE */
void rentVehicle() {
    FILE *fp, *tempFp;
    struct Vehicle v;
    int id, found = 0;

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo vehicles available!\n");
        return;
    }

    tempFp = fopen("temp.txt", "w");

    printf("\nEnter Vehicle ID to Rent: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %f %f %d",
                  &v.id, v.name, v.number,
                  &v.rentHour, &v.rentDay, &v.available) != EOF) {

        if (v.id == id && v.available == 1) {
            v.available = 0;
            found = 1;
        }

        fprintf(tempFp, "%d %s %s %.0f %.0f %d\n",
                v.id, v.name, v.number,
                v.rentHour, v.rentDay, v.available);
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("\nVehicle rented successfully!\n");
    else
        printf("\nVehicle not available!\n");
}

/* RETURN VEHICLE */
void returnVehicle() {
    FILE *fp, *tempFp;
    struct Vehicle v;
    int id, found = 0;

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("\nNo vehicles available!\n");
        return;
    }

    tempFp = fopen("temp.txt", "w");

    printf("\nEnter Vehicle ID to Return: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %f %f %d",
                  &v.id, v.name, v.number,
                  &v.rentHour, &v.rentDay, &v.available) != EOF) {

        if (v.id == id && v.available == 0) {
            v.available = 1;
            found = 1;
        }

        fprintf(tempFp, "%d %s %s %.0f %.0f %d\n",
                v.id, v.name, v.number,
                v.rentHour, v.rentDay, v.available);
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("\nVehicle returned successfully!\n");
    else
        printf("\nInvalid vehicle ID or already available!\n");
}
