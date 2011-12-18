#include "Library.h"
#include "Document.h"
#include "Book.h"
#include "CD.h"
#include "Movie.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <algorithm>

bool sortingName(Document* doc1, Document* doc2)
{

    std::string s1 = doc1->getTitle();
    std::string s2 = doc2->getTitle();

    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    for(unsigned int i = 0; i < s2.size(); ++i) {
         int c1 = s1[i];
         int c2 = s2[i];
         if(c1 != c2) {
              return (c1 < c2);
         }
    }
    return false;
}

int main()
{
    std::cout<<"Creating the Library"<<std::endl;
    Library myLibrary;

    std::cout<<"Adding Books, CDs ans Movies"<<std::endl;
    Book l1("La Première Leçon du Sorcier", "Terry Goodkind","Jusqu'à ce que Richard Cypher sauve cette belle inconnue des griffes de ses poursuivants, il vivait paisiblement dans la forêt. Elle ne consent à lui dire que son nom : Kahlan. Mais lui sait déjà, au premier regard, qu'il ne pourra plus la quitter. Car désormais, le danger rôde en Hartland. Des créatures monstrueuses suivent les pas de l'étrangère. Seul Zedd, son ami le vieil ermite, peut lui venir en aide... en bouleversant son destin. Richard devra porter l'Épée de Vérité et s'opposer aux forces de Darken Rahl, le mage dictateur. Ainsi commence une extraordinaire quête à travers les ténèbres. Au nom de l'amour. A n'importe quel prix.",2003,"Barcelone");
    Book l2("Harry Potter à l'école des sorciers", "J. K. Rowling","Harry Potter, un jeune orphelin, est élevé par son oncle Vernon et sa tante Pétunia, qui lui ont toujours affirmé que ses parents étaient morts lorsqu'il avait un an dans un accident de voiture. Dans la maison du couple irascible, Harry est forcé de dormir dans un placard et est martyrisé par leur fils Dudley. Le jour de son onzième anniversaire, Harry reçoit la visite d'un demi-géant du nom de Hagrid. Ce dernier lui apprend que la magie existe et qu'un monde de sorciers vit en marge et dans l'ignorance des Moldus, les personnes dépourvues de pouvoirs magiques. Il lui révèle également que ses parents étaient en fait de puissants magiciens et qu'il a hérité de leurs pouvoirs. Ils ne sont pas décédés dans un accident, mais assassinés par Lord Voldemort, le Seigneur des Ténèbres dont personne n'ose prononcer le nom, un mage noir très puissant qui avait plongé le monde des sorciers dans le chaos. Voldemort avait tenté de tuer Harry cette nuit-là avec le sortilège de la mort, mais le sort s'était retourné contre lui et il avait disparu, faisant de Harry le seul survivant du sortilège et le sauveur du monde des sorciers, lui laissant une cicatrice en forme d'éclair sur le front. Harry apprend par la bouche d'Hagrid qu'il était, à son insu, la plus grande célébrité du monde des sorciers depuis cette nuit-là, celle de ses 1 an. ",1998, "	Gallimard Jeunesse");
    Book l3("Madame Bovary", "Gustave Flaubert","Fille d'un riche fermier, Emma Rouault épouse Charles Bovary, officier de santé et veuf récent d'une femme tyrannique. Elevée dans un couvent, Emma aspire à vivre dans le monde de rêve dont parlent les romans à l'eau de rose qu'elle y a lu. Un bal au château de Vaubyessard la persuade qu'un tel monde existe, mais le décalage qu'elle découvre avec sa propre vie déclenche chez elle une maladie nerveuse. Son mari décide alors de s'installer dans une autre bourgade, siège de comices agricoles renommées, Yonville-l'Abbaye. Là, elle fait connaissance des personnalités locales, Homais, pharmacien progressiste et athée, le curé Bournisien, Léon Dupuis, clerc de notaire, Rodolphe Boulanger, gentilhomme campagnard. La naissance d'une fille la distrait un peu, mais bientôt Emma cède aux avances de Rodolphe. Elle veut s'enfuir avec son amant qui, lâche, l'abandonne. Emma croit en mourir, traverse d'abord une crise de mysticisme, puis plus tard, au théâtre de Rouen, revoit Léon, revenu de Paris. Elle devient très vite sa maîtresse, lors d'une promenade dans un fiacre. Installée dans sa liaison, Emma Bovary invente des mensonges pour revoir Léon, et dépense des sommes importantes, qu'elle emprunte à un marchand trop complaisant, Lheureux. Un jour, celui-ci exige d'être remboursé. Emma, par peur du jugement qui va être prononcé contre elle, tente d'emprunter auprès de Léon, puis de Rodolphe. Tous deux la repoussent, et Emma s'empoisonne avec l'arsenic dérobé chez le pharmacien. ",1857, "	Michel Lévy frères");
    CD c1("Du monde tout autour", "Louise Attaque", "Rock français", 17);
    CD c2("Born This Way", "Lady Gaga", "pop", 14);
    Movie m1("Titanic", "James Cameron", "Il raconte l'histoire de deux passagers du paquebot Titanic. L'une, Rose, est une passagère de première classe qui tente de se suicider pour se libérer des contraintes imposées par son entourage, et le second, Jack, est un vagabond embarqué à la dernière minute en troisième classe pour retourner aux États-Unis. Ils se rencontrent par hasard lors de la tentative de suicide de Rose et vivent une histoire d'amour vite troublée par le naufrage du paquebot.", "Drame","Leonardo DiCaprio, Kate Winslet");
    Movie m2("Le Seigneur des anneaux : la communauté de l'anneau", "Peter Jackson ", "Dans ce chapitre de la trilogie, le jeune et timide Hobbit, Frodon Sacquet, hérite d'un anneau. Bien loin d'être une simple babiole, il s'agit de l'Anneau Unique, un instrument de pouvoir absolu qui permettrait à Sauron, le Seigneur des ténèbres, de régner sur la Terre du Milieu et de réduire en esclavage ses peuples. À moins que Frodon, aidé d'une Compagnie constituée de Hobbits, d'Hommes, d'un Magicien, d'un Nain, et d'un Elfe, ne parvienne à emporter l'Anneau à travers la Terre du Milieu jusqu'à la Crevasse du Destin, lieu où il a été forgé, et à le détruire pour toujours. Un tel périple signifie s'aventurer très loin en Mordor, les terres du Seigneur des ténèbres, où est rassemblée son armée d'Orques maléfiques... La Compagnie doit non seulement combattre les forces extérieures du mal mais aussi les dissensions internes et l'influence corruptrice qu'exerce l'Anneau lui-même. L'issue de l'histoire à venir est intimement liée au sort de la Compagnie. ", "Fantastique", "Elijah Wood, Sean Astin, Ian McKellen");

    myLibrary.addDoc(&l1);
    myLibrary.addDoc(&l2);
    myLibrary.addDoc(&l3);
    myLibrary.addDoc(&c1);
    myLibrary.addDoc(&c2);
    myLibrary.addDoc(&m1);
    myLibrary.addDoc(&m2);

    std::cout << "\n*** Sorting by name ... " << std::endl;
    myLibrary.sort(&sortingName);
    std::vector<Document*> doc = myLibrary.search("");
    for(unsigned int i =0;i<doc.size();i++)
    {
        std::cout<<" > "<<doc[i]->getTitle()<<std::endl;
    }

    std::cout<<"Number of documents : "<<myLibrary.numberDocument()<<std::endl;
    std::cout<<"Export to html"<<std::endl;
    myLibrary.exportHTML();

    return 0;
}


