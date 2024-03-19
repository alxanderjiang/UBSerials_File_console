#include"satpos.h"

//�����ǳ���ĳ�ʼʾ���ļ�
const char SATF_BDS[100] = "Example/tarc0320_UTC_0.txt";//RINEX���������ļ���
const char SATF_GPS[100] = "Example/brdc0320.txt";//RINEXGPS�����ļ���
const char OBSF[100] = "Example/259003200.21o";//RINEX�۲��ļ���
const char OBSB[100] = "Example/20220927OBS+NAV+PSRPOS+IONUTC.dat";//�����ƹ۲��ļ���
const char OBSB_B[100] = "Example/BDStest.dat";

int main() {
    
    //��ʼ����������
    int filemode = 0, sysmode = 0, resultmode = 0;
    printf("/**���㶨λ������ղ��ٳ���**/\n1.RINEX�ļ���\n2.�������ļ�\nYour choice:");
    scanf("%d", &filemode);
    printf("1.GPS;\n2.BDS\nYour choice:");
    scanf("%d", &sysmode);
    printf("1.����λ��;\n2.��վλ��\nYour choice:");
    scanf("%d", &resultmode);
    
    system("cls");//����
    
    //����
    if (filemode == 1 && sysmode == 1 && resultmode == 1) {
        printf("/*�۲��ļ� %s GPS����λ���ٶȼ���������*/\n", OBSF);
        printf("PRN | X | Y | Z | X_speed | Y_speed | Z_speed | Dt | Dt_speed\n");
        RINEX_GPS_sat(SATF_GPS, OBSF);
    }
    else if (filemode == 1 && sysmode == 1 && resultmode == 2) {
        printf("/*�۲��ļ� %s GPS��ϵͳ��վλ���ٶȼ���������*/\n", OBSF);
        printf("X | Y | Z | Clock_Dt | X_speed | Y_speed | Z_speed | Clock_Dt_speed | B | L | H | satsum\n");
        RINEX_GPS_sat(SATF_GPS, OBSF, 2);
    }
    else if (filemode == 1 && sysmode == 2 && resultmode == 1) {
        printf("/*�۲��ļ� %s BDS����λ���ٶȼ���������*/\n", OBSF);
        printf("PRN | X | Y | Z | X_speed | Y_speed | Z_speed | Dt | Dt_speed\n");
        RINEX_BDS_sat(SATF_BDS, OBSF);
    }
    else if (filemode == 1 && sysmode == 2 && resultmode == 2) {
        printf("/*�۲��ļ� %s BDS��ϵͳ��վλ���ٶȼ���������*/\n", OBSF);
        printf("X | Y | Z | Clock_Dt | X_speed | Y_speed | Z_speed | Clock_Dt_speed | B | L | H | satsum\n");
        RINEX_BDS_sat(SATF_BDS, OBSF, 2);
    }
    else if (filemode == 2 && sysmode == 1 && resultmode == 1) {
        printf("/*�۲��ļ� %s GPS����λ���ٶȼ���������*/\n", OBSB);
        printf("PRN | X | Y | Z | X_speed | Y_speed | Z_speed | Dt | Dt_speed\n");
        BINEARY_sat(OBSB, 1);
    }
    else if (filemode == 2 && sysmode == 1 && resultmode == 2) {
        printf("/*�۲��ļ� %s GPS��ϵͳ��վλ���ٶȼ���������*/\n", OBSB);
        printf("X | Y | Z | Clock_Dt | X_speed | Y_speed | Z_speed | Clock_Dt_speed | B | L | H | satsum\n");
        BINEARY_sat(OBSB, 2);
    }
    else if (filemode == 2 && sysmode == 2 && resultmode == 1) {
        printf("/*�۲��ļ� %s BDS����λ���ٶȼ���������*/\n", OBSB_B);
        printf("PRN | X | Y | Z | X_speed | Y_speed | Z_speed | Dt | Dt_speed\n");
        BINEARY_sat(OBSB_B, 3);
    }
    else if (filemode == 2 && sysmode == 2 && resultmode == 2) {
        printf("/*�۲��ļ� %s BDS��ϵͳ��վλ���ٶȼ���������*/\n", OBSB_B);
        printf("X | Y | Z | Clock_Dt | X_speed | Y_speed | Z_speed | Clock_Dt_speed | B | L | H | satsum\n");
        BINEARY_sat(OBSB_B, 4);
    }
    return 0;
}