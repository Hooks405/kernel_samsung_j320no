#include <stdio.h>
#include <stdlib.h>
void load_menu(void);
void Compile(void);
void Flash(void);
void Clean(void);
 
int main(int argc, char** argv)
{
    load_menu();
    return 0;
}
 
void load_menu(void)
{
    int choice;
 
    do
    {
   system("echo 'J3ltespr'");
        printf("1. Compile\n");
        printf("2. Flash\n");
	printf("3. Clean\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1: Compile();
                break;
            case 2: Flash();
                break;
	    case 3: Clean();
		break;
            case 4: printf("Quitting program!\n");
		system("rm build");
                exit(0);
                break;
            default: printf("Invalid choice!\n");
                break;
        }
 
    } while (choice != 3);
 
}
 
void Compile(void)
{
system
("chmod 775 arch/arm/tools/mkbootimg ; make -j4 msm8916_sec_defconfig VARIANT_DEFCONFIG=msm8916_sec_defconfig SELINUX_DEFCONFIG=selinux_defconfig ; make -j4 ;mkdir system;mkdir system/lib/;mkdir system/lib/modules;rsync -r `find -type f -name '*.ko'` system/lib/modules;cp arch/arm/boot/zImage arch/arm/tools/zImage;mv system arch/arm/tools/;cd arch/arm/tools;cd boot.img-ramdisk;find . | cpio -o -H newc | gzip > ../boot.img-ramdisk.gz;cd ..;./mkbootimg --kernel zImage  --ramdisk boot.img-ramdisk.gz --ramdisk_offset 01300000 --tags_offset 00000100 --base 00200000 --pagesize 4096 -o boot.img;zip -r tmp META-INF boot.img system;rm -rf system boot.img zImage boot.img-ramdisk.gz;mv -f tmp.zip ../../../kernel-$(date +%Y%m%d)-3.4.0-UNOFFICIAL-j3ltespr.zip;clear");
system("rm build");
   return;
}     

void Flash(void)
{

system("echo 'Waiting for device';adb wait-for-device;mkdir tmp ;cp kernel-$(date +%Y%m%d)-3.4.0-UNOFFICIAL-delos3geur.zip tmp/;cd tmp;unzip *.zip;echo 'PUSHING BOOT.IMG';adb push boot.img /sdcard/boot.img;echo 'Flashing ';adb shell 'su -c 'dd if=/sdcard/boot.img of=/dev/block/mmcblk0p8'';adb shell rm /sdcard/boot.img;adb shell 'su -c 'reboot'';cd ..;rm -rf tmp;clear");
system("rm build");
return;
}
void Clean(void)
{
system("make -j4 mrproper");
system("rm build");
return;
}

