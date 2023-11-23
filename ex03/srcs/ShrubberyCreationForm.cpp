/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:59:19 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/23 15:26:39 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target,  145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj){
    *this = obj; 
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    setSigned(obj.getSigned());
    setName(obj.getName());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void    ShrubberyCreationForm::execute(const Bureaucrat &b) const{
    checkExec(b);
    std::ofstream file;
    std::string fileName;
    
    fileName = getName();
    fileName.append("_shrubbery");
    file.open(fileName.c_str());
    if (file.fail())
    {
        std::cout << " can't open the file. " << std::endl;
        return ;
    }
    
    std::string contents = 
"%%%%%%%%%%%%%%%%                                                               \n\
%%%%%%%%%%%%%%%%                                                                \n\
%%%%%%%                             #*##/*#                                     \n\
                               #####(/#/###*###                                 \n\
                             #(//#(////((*/((//#####                            \n\
                          ###%(((&&%(%&(/%/**/((##((#                           \n\
                         #((,(##(#(#/%%///&###(#/*/#((                          \n\
                        #//*///*/%&%(/(*%/%%%&#%(((/(*#                         \n\
                     //(%/%((@(/%&&/#%&&(%(*/&((%#/%/#%(                        \n\
                    (%(%&&&#((/%%(/##&&((//(&%(&%&#((%#((                       \n\
                   %%##(#%(&&%%#*///////&%/(#/#/%/*#*/*(//(                     \n\
                 ((#%(%%%//#@@&&@&#&%@&*%&%#%///(&&&(&/***//                    \n\
                #(%&((&&&%@&&@(&&(&&@@@&&&&&(&#%(/*#//&%%#(*/                   \n\
               (&&&%&((&%&#%%&&&(#&&&(((#%&#((%@#/&#####%#/(//                  \n\
               #&&&(%&@&&&&&&(@@&@@&&&@@&/##(%(/&(%#*(,(#%&**//                 \n\
               (#%%(&%%&%&&&&(((&@@@@@@&&@&&&%&%#/(%*#*(%(//((#/                \n\
               *&@%&&&&&@&&&#@&%@*%#&#(*(&@&&&%#&*%%&&##%(#%&#*##               \n\
               *&&%@@@@&&%&&#&&&&%&%%#%%&&@&#&&&#%&&&%&&&&/(#%%&                \n\
                %#&&&#/%@&&&&&&@@&&##&#@#&&%(@&&&&*/%&&%&%&%%%%                 \n\
                   (&&/#&%#&@&&@&&&&&@@#&/@&&&&&@&&%(*&*/%%*                    \n\
                            #(*(,,,*@@@(,&&&#(&&%*,,%,%*                        \n\
                                    *@@*@@*                                     \n\
    .            .      .           @@*@@&@      .           .                  \n\
/***//*///(//*/***/*//*((/////*////*//*((////////((////(/(////*/(*/(////*///***/\n\
*/.*,*****,.****/*(/,//***,**/(,**/*,/*//*/////,*****(/*/*/***(//*////////,/////\n\
**,*,**,,* //,/*/,(,**.*******/*/*/**/,*****./*/,/./.*,*.***/******/*,*,*,*,/**/\n\
/**/*/*.***/,/*/*/*/,/, */*/***///*,/*(///***/***//,///*//*(/,/,/(/////*,,*,,/**\n\
//*/*//,/(*,,,*.*/*. //,,**//,*/.,.,/*..#*.*/,**/*//.***(/***//*/****//,/*,//*.*\n\
/.,./*/(,*/*.*/,****,//**,*,,.*/*,,,/***////(*,//,***/,(,//.**,********/*/////(*\n\n";
    
    file << contents;
    file.close();

     std::cout << ANSI_COLOR_ORANGE << "our tree already in the " << fileName << ANSI_COLOR_RESET << std::endl;
    
}