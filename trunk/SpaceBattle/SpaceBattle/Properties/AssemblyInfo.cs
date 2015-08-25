using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Windows;

// Les informations generales relatives a un assembly dependent de 
// l'ensemble d'attributs suivant. Changez les valeurs de ces attributs pour modifier les informations
// associees a un assembly.
[assembly: AssemblyTitle("SpaceBattle")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyCompany("")]
[assembly: AssemblyProduct("SpaceBattle")]
[assembly: AssemblyCopyright("Copyright ©  2011")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyCulture("")]

// L'affectation de la valeur false a ComVisible rend les types invisibles dans cet assembly 
// aux composants COM. Si vous devez acceder a un type dans cet assembly a partir de 
// COM, affectez la valeur true a l'attribut ComVisible sur ce type.
[assembly: ComVisible(false)]

//Pour commencer a generer des applications localisables, definissez 
//<UICulture>CultureYouAreCodingWith</UICulture> dans votre fichier .csproj
//dans <PropertyGroup>. Par exemple, si vous utilisez le français
//dans vos fichiers sources, definissez <UICulture> a fr-FR. Puis, supprimez les marques de commentaire de
//l'attribut NeutralResourceLanguage ci-dessous. Mettez a jour "fr-FR" dans
//la ligne ci-apres pour qu'elle corresponde au parametre UICulture du fichier projet.

//[assembly: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)]


[assembly: ThemeInfo(
    ResourceDictionaryLocation.None, //où se trouvent les dictionnaires de ressources specifiques a un theme
    //(utilise si une ressource est introuvable dans la page, 
    // ou dictionnaires de ressources de l'application)
    ResourceDictionaryLocation.SourceAssembly //où se trouve le dictionnaire de ressources generique
    //(utilise si une ressource est introuvable dans la page, 
    // dans l'application ou dans l'un des dictionnaires de ressources specifiques a un theme)
)]


// Les informations de version pour un assembly se composent des quatre valeurs suivantes :
//
//      Version principale
//      Version secondaire 
//      Numero de build
//      Revision
//
// Vous pouvez specifier toutes les valeurs ou indiquer les numeros de build et de revision par defaut 
// en utilisant '*', comme indique ci-dessous :
// [assembly: AssemblyVersion("1.0.*")]
[assembly: AssemblyVersion("1.0.0.0")]
[assembly: AssemblyFileVersion("1.0.0.0")]

[assembly: System.Runtime.CompilerServices.InternalsVisibleTo("TestProject SpaceBattleView")]