#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int main(int argc, char **argv)
{
    char inBuff[SIZE];
    int numOfRaws, i, ID, tip;
    double consumption;

    FILE *pFlie;
    FILE *qFlie;
    if(argc < 3){
        printf("You need to provide more information to run the program.\n");
        exit(-1);
    }
    pFlie = fopen(argv[1], "r");
    qFlie = fopen(argv[2], "w");
    if (pFlie != NULL)
    {
        fgets(inBuff, SIZE, pFlie);
        sscanf(inBuff, "%i", &numOfRaws);

        for (i = 0; i < numOfRaws; i++)
        {
            fgets(inBuff, SIZE, pFlie);
            sscanf(inBuff, "%i %lf %i", &ID, &consumption, &tip);

            fprintf(qFlie, "%s %i %s %.2lf\n", "Total tips earned on ", ID, "= ", (consumption * tip / 100));
        }

        fclose(qFlie);
        fclose(pFlie);
    }
    else
    {
        printf("Error! You need to specify input and output filename by CLA.\n");
        exit(-1);
    }

    return 0;
}