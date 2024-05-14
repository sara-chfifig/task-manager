#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 50

// Fonction pour ajouter une tache à la liste
void addTask(char tasks[][MAX_TASK_LENGTH], int *taskCount, char *description) {
    if (*taskCount < MAX_TASKS) {
        strcpy(tasks[*taskCount], description);
        (*taskCount)++;
        printf("Tache ajoutee avec succes.\n");
    } else {
        printf("La liste de taches est pleine.\n");
    }
}

// Fonction pour supprimer une tache de la liste
void deleteTask(char tasks[][MAX_TASK_LENGTH], int *taskCount, int index) {
    if (index >= 0 && index < *taskCount) {
        for (int i = index; i < *taskCount - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }
        (*taskCount)--;
        printf("Tache supprimee avec succes.\n");
    } else {
        printf("Indice de tache invalide.\n");
    }
}

// Fonction pour afficher toutes les taches de la liste
void displayTasks(char tasks[][MAX_TASK_LENGTH], int taskCount) {
    if (taskCount == 0) {
        printf("Aucune tache a afficher.\n");
    } else {
        printf("Liste des taches :\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }
}

int main() {
    char tasks[MAX_TASKS][MAX_TASK_LENGTH];
    int taskCount = 0;
    char description[MAX_TASK_LENGTH];
    int choice, index;

    while (1) {
        printf("\nMenu :\n");
        printf("1. Ajouter une tache\n");
        printf("2. Supprimer une tache\n");
        printf("3. Afficher les taches\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Entrez la description de la tache : ");
                scanf(" %[^\n]s", description);
                addTask(tasks, &taskCount, description);
                break;
            case 2:
                printf("Entrez l'indice de la tache a supprimer : ");
                scanf("%d", &index);
                deleteTask(tasks, &taskCount, index - 1);
                break;
            case 3:
                displayTasks(tasks, taskCount);
                break;
            case 4:
                printf("Au revoir !\n");
                exit(0);
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}
