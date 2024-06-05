            char opsi[20];

            do {
                printf("APAKAH KAMU YAKIN INGIN KELUAR (Y/T) : ");
                scanf(" %s", opsi);  // No & needed for a string (array) variable

                if (strcmp(opsi, "Y") == 0) {
                    printf("Keluar\n");
                } else if (strcmp(opsi, "T") == 0) {
                    printf("Tidak jadi\n");
                }
            } while (strcmp(opsi, "Y") != 0 && strcmp(opsi, "T") != 0);