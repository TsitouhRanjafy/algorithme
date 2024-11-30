Joueur1 = input("Entrer le nom du 1er joueur:").capitalize();
PV1 = int(input("Et son nombre de PV:"));
Joueur2 = input("Entrer le nom du 2er joueur:").capitalize();
PV2 = int(input("Et son nombre de PV:"));
annonce = "+ "+Joueur1+" ("+str(PV1)+" PV) affronte "+Joueur2+" ("+str(PV2)+" PV) +";

print("\n\n");
print("\t","+" * len(annonce));
print("\t",annonce)
print("\t","+" * len(annonce),"\n");


print("Quelle attaque voulez-vous utiliser?");
print("1. Charge (-20 PV)");
print("2. Tonnerre (-50 PV)\n");

type_d_attaque = input(":").lower();

dega = 0;
if (type_d_attaque == '1') or (type_d_attaque == 'charge'):
    dega = 20
elif (type_d_attaque == '2') or (type_d_attaque == 'tonnerre'):
    dega = 50

PV2-=dega;
message1 = Joueur1+" attaque "+Joueur2+" qui perd "+str(dega)+" PV"
message2 = Joueur2+" a maintenant "+str(PV2)+" PV"

message2 += " " * (len(message1)-len(message2));

print("\n\n");
print("\t","+" * (len(message1)+4))
print("\t","+ "+message1+" +");
print("\t","+ "+message2+" +");
print("\t","+" * (len(message1)+4),"\n")

print("Quelle attaque voulez-vous utiliser?");
print("1. Charge (-20 PV)");
print("2. Tonnerre (-50 PV)\n");

type_d_attaque = input(":").lower();

dega = 0;
if (type_d_attaque == '1') or (type_d_attaque == 'charge'):
    dega = 20
elif (type_d_attaque == '2') or (type_d_attaque == 'tonnerre'):
    dega = 50


PV1-=dega;
message1 = Joueur2+" attaque "+Joueur1+" qui perd "+str(dega)+" PV"
message2 = Joueur1+" a maintenant "+str(PV1)+" PV"

message2 += " " * (len(message1)-len(message2));

print("\t","+" * (len(message1)+4))
print("\t","+ "+message1+" +");
print("\t","+ "+message2+" +")
print("\t","+" * (len(message1)+4),"\n\n")

message3 = "Résultat du combat:" 
message1 = Joueur1+" a "+str(PV1)+" PV"
message2 = Joueur2+" a "+str(PV2)+" PV"
max_size = max(max(len(message1),len(message2)),len(message3))
message3 = message3+ " " * (max_size - len(message3)) 
message1 = message1+ " " * (max_size - len(message1))
message2 = message2+ " " * (max_size - len(message2))

print("\t","+" * (max_size+4))
print("\t","+ "+message3+" +")
print("\t","+ "+message1+" +")
print("\t","+ "+message2+" +")
print("\t","+" * (max_size+4))

if PV1 < PV2:
    print("\t +",Joueur2,"a gagné +");
elif PV2 < PV1:
    print("\t +",Joueur1," a gagné +");