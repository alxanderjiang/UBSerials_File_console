#include"satpos.h"

//下面是程序的初始示例文件
const char SATF_BDS[100] = "Example/tarc0320_UTC_0.txt";//RINEX北斗星历文件名
const char SATF_GPS[100] = "Example/brdc0320.txt";//RINEXGPS星历文件名
const char OBSF[100] = "Example/259003200.21o";//RINEX观测文件名
const char OBSB[100] = "Example/20220927OBS+NAV+PSRPOS+IONUTC.dat";//二进制观测文件名
const char OBSB_B[100] = "Example/BDStest.dat";

int main() {
    
    //初始化程序设置
    int filemode = 0, sysmode = 0, resultmode = 0;
    printf("/**单点定位与多普勒测速程序**/\n1.RINEX文件；\n2.二进制文件\nYour choice:");
    scanf("%d", &filemode);
    printf("1.GPS;\n2.BDS\nYour choice:");
    scanf("%d", &sysmode);
    printf("1.卫星位置;\n2.测站位置\nYour choice:");
    scanf("%d", &resultmode);
    
    system("cls");//清屏
    
    //运算
    if (filemode == 1 && sysmode == 1 && resultmode == 1) {
        printf("/*观测文件 %s GPS卫星位置速度计算结果如下*/\n", OBSF);
        printf("PRN | X | Y | Z | X_speed | Y_speed | Z_speed | Dt | Dt_speed\n");
        RINEX_GPS_sat(SATF_GPS, OBSF);
    }
    else if (filemode == 1 && sysmode == 1 && resultmode == 2) {
        printf("/*观测文件 %s GPS单系统测站位置速度计算结果如下*/\n", OBSF);
        printf("X | Y | Z | Clock_Dt | X_speed | Y_speed | Z_speed | Clock_Dt_speed | B | L | H | satsum\n");
        RINEX_GPS_sat(SATF_GPS, OBSF, 2);
    }
    else if (filemode == 1 && sysmode == 2 && resultmode == 1) {
        printf("/*观测文件 %s BDS卫星位置速度计算结果如下*/\n", OBSF);
        printf("PRN | X | Y | Z | X_speed | Y_speed | Z_speed | Dt | Dt_speed\n");
        RINEX_BDS_sat(SATF_BDS, OBSF);
    }
    else if (filemode == 1 && sysmode == 2 && resultmode == 2) {
        printf("/*观测文件 %s BDS单系统测站位置速度计算结果如下*/\n", OBSF);
        printf("X | Y | Z | Clock_Dt | X_speed | Y_speed | Z_speed | Clock_Dt_speed | B | L | H | satsum\n");
        RINEX_BDS_sat(SATF_BDS, OBSF, 2);
    }
    else if (filemode == 2 && sysmode == 1 && resultmode == 1) {
        printf("/*观测文件 %s GPS卫星位置速度计算结果如下*/\n", OBSB);
        printf("PRN | X | Y | Z | X_speed | Y_speed | Z_speed | Dt | Dt_speed\n");
        BINEARY_sat(OBSB, 1);
    }
    else if (filemode == 2 && sysmode == 1 && resultmode == 2) {
        printf("/*观测文件 %s GPS单系统测站位置速度计算结果如下*/\n", OBSB);
        printf("X | Y | Z | Clock_Dt | X_speed | Y_speed | Z_speed | Clock_Dt_speed | B | L | H | satsum\n");
        BINEARY_sat(OBSB, 2);
    }
    else if (filemode == 2 && sysmode == 2 && resultmode == 1) {
        printf("/*观测文件 %s BDS卫星位置速度计算结果如下*/\n", OBSB_B);
        printf("PRN | X | Y | Z | X_speed | Y_speed | Z_speed | Dt | Dt_speed\n");
        BINEARY_sat(OBSB_B, 3);
    }
    else if (filemode == 2 && sysmode == 2 && resultmode == 2) {
        printf("/*观测文件 %s BDS单系统测站位置速度计算结果如下*/\n", OBSB_B);
        printf("X | Y | Z | Clock_Dt | X_speed | Y_speed | Z_speed | Clock_Dt_speed | B | L | H | satsum\n");
        BINEARY_sat(OBSB_B, 4);
    }
    return 0;
}