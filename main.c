#include <stdio.h>
#include <math.h>
const double Pi = 3.14159265;
const double yercekimi_sabit[]={3.59, 8.87, 9.81, 3.77, 25.95, 11.08, 10.67, 14.07};
const char *gezegen_isim[]={"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};
const int gezegen_sayisi = 8;
//deneyleri sağlayan fonksiyonlar
void serbest_dusme(const double *yercekimi_ptr) {
    double t, h;
printf("\n--- Serbest Dusme Deneyi ---\n");
    printf("Dusus suresini saniye cinsinden giriniz: ");
    scanf("%lf", &t);
t = (t < 0) ? -t : t;
printf("Girilen sure (mutlak deger): %.2f saniye\n\nSimulasyon sonuclari:\n", t);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
h = 0.5 * g * (t * t);
printf("%-10s -> Yukseklik: %.2f metre\n", *(gezegen_isim + i), h);
} }

void yukari_atis(const double *yercekimi_ptr) {
    double v, h;
printf("\n---  Yukari Atis Deneyi ---\n");
    printf("Atış hızını m/s cinsinden giriniz: ");
    scanf("%lf", &v);
v = (v < 0) ? -v : v;
printf("Girilen hiz (mutlak deger): %.2f m/s\n\nSimulasyon sonuclari:\n", v);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
h = (v*v) / (2*g);
printf("%-10s -> Yukseklik(max): %.2f metre\n", *(gezegen_isim + i), h);
} }

void agirlik(const double *yercekimi_ptr) {
    double m, G;
printf("\n--- Agirlik Deneyi ---\n");
    printf("Cismin kütlesini kilogram cinsinden giriniz: ");
    scanf("%lf", &m);
m = (m < 0) ? -m : m;
printf("Girilen kütle (mutlak deger): %.2f kilogram\n\nSimulasyon sonuclari:\n", m);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
G=m*g;
printf("%-10s -> Agirlik: %.2f Newton\n", *(gezegen_isim + i), G);
} }

void k_pot_enerji(const double *yercekimi_ptr) {
    double h,m,Ep;
printf("\n--- Kütlecekimsel Potansiyel Enerji Deneyi ---\n");
    printf("Cismin kütlesini kilogram cinsinden giriniz: ");
    scanf("%lf", &m);
m = (m < 0) ? -m : m;
    printf("Cismin yerden yuksekligini metre cinsinden giriniz: ");
    scanf("%lf", &h);
h = (h < 0) ? -h : h;
printf("Girilen kütle (mutlak deger): %.2f kilogram yukseklik(mutlak deger): %.2f metre\n\nSimulasyon sonuclari:\n", m,h);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
Ep=m*g*h;
printf("%-10s -> Potansiyel enerji: %.2f Joule\n", *(gezegen_isim + i), Ep);
} }

void h_basinc(const double *yercekimi_ptr) {
    double h,p,P;
printf("\n--- Hidrostatik Basinc deneyi ---\n");
    printf("Sivinin birim hacimdeki kutlesini(yogunlugunu) kg/m³ cinsinden giriniz: ");
    scanf("%lf", &p);
p = (p < 0) ? -p : p;
    printf("Sivinin derinligini metre cinsinden giriniz: ");
    scanf("%lf", &h);
h = (h < 0) ? -h : h;
printf("Girilen birim hacimde kutle (mutlak deger): %.2f kg/m³ derinlik(mutlak deger): %.2f metre\n\nSimulasyon sonuclari:\n", p,h);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
P=p*g*h;
printf("%-10s -> Hidrostatik basinc: %.2f Pascal\n", *(gezegen_isim + i), P);
} }

void a_kaldirma_kuvveti(const double *yercekimi_ptr) {
    double V,p,Fk;
printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    printf("Sivinin birim hacimdeki kutlesini(yogunluk) kg/m³ cinsinden giriniz: ");
    scanf("%lf", &p);
p = (p < 0) ? -p : p;
    printf("Cismin batan hacmini m³ cinsinden giriniz: ");
    scanf("%lf", &V);
V = (V < 0) ? -V : V;
printf("Girilen birim hacimde kutle(yogunluk) (mutlak deger): %.2f kg/m³ cismin batan hacmi(mutlak deger): %.2f m³\n\nSimulasyon sonuclari:\n", p,V);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
Fk=p*g*V;
printf("%-10s -> Kaldirma kuvveti: %.2f Newton\n", *(gezegen_isim + i), Fk);
} }

void sarkac_periyodu(const double *yercekimi_ptr) {
    double L,T;
printf("\n--- Basit Sarkac Periyodu Deneyi ---\n");
    printf("Sarkacin ip uzunlugunu metre cinsinden giriniz: ");
    scanf("%lf", &L);
L = (L < 0) ? -L : L;
printf("Girilen sarkac ip uzunlugu (mutlak deger): %.2f m\n\nSimulasyon sonuclari:\n", L);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
T = 2*Pi*sqrt(L / g);
printf("%-10s -> Periyot: %.2f saniye\n", *(gezegen_isim + i), T);
} }

void ip_gerilmesi(const double *yercekimi_ptr) {
    double m,T;
printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    printf("Cismin kütlesini kilogram cinsinden giriniz: ");
    scanf("%lf", &m);
m = (m < 0) ? -m : m;
printf("Girilen cisim kutlesi (mutlak deger): %.2f kg\n\nSimulasyon sonuclari:\n", m);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
T = m*g;
printf("%-10s -> Ip gerilmesi: %.2f Newton\n", *(gezegen_isim + i), T);
} }

void asansor(const double *yercekimi_ptr) {
    double m,a,N;
    int yon;
printf("\n--- Asansör Deneyi ---\n");
    printf("Cismin kütlesini kilogram cinsinden giriniz: ");
    scanf("%lf", &m);
m = (m < 0) ? -m : m;
    printf("Asansorun ivmesini m/s^2 cinsinden giriniz: "); 
    scanf("%lf", &a); 
a = (a < 0) ? -a : a;
printf("\n1. Yukari yonlu hizlanan (veya asagi yavaslayan)\n2. Asagi yonlu hizlanan (veya yukari yavaslayan)\n");
printf("\nAsansorun hareket yonunu seciniz:");
scanf("%d", &yon);
printf("Girilen cisim kutlesi (mutlak deger): %.2f kg,ivmesi %.2f m/s\n\nSimulasyon sonuclari:\n", m,a);
for (int i = 0; i < gezegen_sayisi; i++) {
double g = *(yercekimi_ptr + i);
N= (yon == 1) ? (m*(g+a)) : (m*(g-a));
printf("%-10s -> Etkin agirlik: %.2f Newton\n", *(gezegen_isim + i), N);
} }


int main(){//Başlangıç ve isim girme kısmı
	char isim[20];
	int secim;
	printf("Bilim insanının adını giriniz:");
	scanf("%s",isim);
	printf("\nBilim insani %s uzay simülasyonu uygulamasına hoşgeldiniz.\n", isim);
do {//do-while ile tekrarlayan menü ve deney uygulaması
printf("\n--- DENEY LISTESI ---\n");
printf("1. Serbest Dusme Deneyi\n");
printf("2. Yukari Atis Deneyi\n");	
printf("3. Agirlik Deneyi\n");	
printf("4. Kütlecekimsel Potansiyel Enerji Deneyi\n");
printf("5. Hidrostatik Basinc Deneyi\n");	
printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
printf("7. Basit Sarkac Periyodu Deneyi\n");printf("8. Sabit Ip Gerilmesi Deneyi\n");
printf("9. Asansor Deneyi\n");
printf("-1. Cikis\n");
printf("Seciminiz: ");
scanf("%d", &secim);
while(getchar() != '\n');

switch(secim){//menüde uygun seçime göre fonksiyona yönlendirme
	case -1:printf("Program sonlandiriliyor...\n");
                break;
    case 1:
    	serbest_dusme(yercekimi_sabit);
    	break;
    case 2:
    	yukari_atis(yercekimi_sabit);
    	break;
    case 3:
    	agirlik(yercekimi_sabit);
    	break;
    case 4:
    	k_pot_enerji(yercekimi_sabit);
    	break;
	case 5:
		h_basinc(yercekimi_sabit);
		break;
	case 6:
		a_kaldirma_kuvveti(yercekimi_sabit);
		break;
	case 7:
		sarkac_periyodu(yercekimi_sabit);
		break;
	case 8:
		ip_gerilmesi(yercekimi_sabit);
		break;
	case 9:
		asansor(yercekimi_sabit);
		break;
	default:printf("Gecersiz secim!Lütfen tekrar deneyin.\n");
	break;
}}while(secim!=-1);	
return 0;	
	}
