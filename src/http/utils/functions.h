#ifndef HTTP_UTILS_COMMON_H
#define HTTP_UTILS_COMMON_H

#include <string>


namespace Http {
    namespace Utils {
        
        /**
         * Trim the spaces and linebreaks
         * from the begin of the given content.
         * 
         * @param const std::string & content
         * @param const std::string & delimiters
         * @return void
         */
        inline void leftTrim(std::string & content, const std::string & delimiters = " \f\n\r\t\v")
        {
            content.erase(0, content.find_first_not_of(delimiters));
        }

        /**
         * Trim the spaces and linebreaks
         * from the end of the given content.
         * 
         * @param const std::string & content
         * @param const std::string & delimiters
         * @return void
         */
        inline void rightTrim(std::string & content, const std::string & delimiters = " \f\n\r\t\v")
        {
            content.erase(content.find_last_not_of(delimiters) + 1);
        }

        /**
         * Trim content from right and left.
         * 
         * @param std::string & content
         * @param const std::string & delimiters
         * @return void
         */
        inline void trim(std::string & content, const std::string & delimiters = " \f\n\r\t\v")
        {
            leftTrim(content, delimiters);
            rightTrim(content, delimiters);
        }

    }
}


#endif // HTTP_UTILS_COMMON_H