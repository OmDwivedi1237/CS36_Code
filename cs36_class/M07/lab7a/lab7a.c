#include <stdio.h>


#define FILE_NAME "hardware.dat"
#define MAX_R 100

void initFile();
void enterInitData();
void delData(unsigned int recordNum);
void addData();
void printData();

typedef struct {
  unsigned int record;
  char toolName[20];
  unsigned int quantity;
  double cost;
} Tool;

int main () {
  initFile();

  // Step 1: Enter equipment information
  enterInitData();

  // Step 2: Delete record #24 (Saw)
  delData(24);

  // Step 3: Add a new record
  addData();

  // Step 4: Print the contents of the file
  printData();  
  return 0;
}


void initFile() {
    FILE *file = fopen(FILE_NAME, "wb");
    Tool emptyTool = {0, "", 0, 0.0};
    for (int i = 0; i < MAX_R; i++) {
        fwrite(&emptyTool, sizeof(Tool), 1, file);
    }
    fclose(file);
}

void enterInitData() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        perror("File opening failed");
        return;
    }

    Tool tool;
    char continueInput;

    do {
        printf("Enter record number: ");
        scanf("%u", &tool.record);
        printf("Enter tool name: ");
        scanf("%s", tool.toolName);
        printf("Enter quantity: ");
        scanf("%u", &tool.quantity);
        printf("Enter cost: ");
        scanf("%lf", &tool.cost);

        fseek(file, (tool.record - 1) * sizeof(Tool), SEEK_SET);
        fwrite(&tool, sizeof(Tool), 1, file);

        printf("Do you want to enter another record? (y/n): ");
        scanf(" %c", &continueInput);

    } while (continueInput == 'y' || continueInput == 'Y');

    fclose(file);
}

void delData(unsigned int recordNum) {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        perror("File opening failed");
        return;
    }

    Tool emptyTool = {0, "", 0, 0.0};
    fseek(file, (recordNum - 1) * sizeof(Tool), SEEK_SET);
    fwrite(&emptyTool, sizeof(Tool), 1, file);

    fclose(file);
}

void addData() {
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        perror("File opening failed");
        return;
    }

    Tool newTool;
    printf("Enter new record number: ");
    scanf("%u", &newTool.record);
    printf("Enter tool name: ");
    scanf("%s", newTool.toolName);
    printf("Enter quantity: ");
    scanf("%u", &newTool.quantity);
    printf("Enter cost: ");
    scanf("%lf", &newTool.cost);

    fseek(file, (newTool.record - 1) * sizeof(Tool), SEEK_SET);
    fwrite(&newTool, sizeof(Tool), 1, file);

    fclose(file);
}

void printData() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    Tool tool;
    printf("%-10s %-20s %-10s %-10s\n", "Record#", "Tool Name", "Quantity", "Cost");
    while (fread(&tool, sizeof(Tool), 1, file)) {
        if (tool.record != 0) {
            printf("%-10u %-20s %-10u $%-10.2f\n", tool.record, tool.toolName, tool.quantity, tool.cost);
        }
    }

    fclose(file);
}
