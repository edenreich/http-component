#ifndef URL_H
#define URL_H

#include "interfaces/client_interface.h"
#include "interfaces/url_interface.h"

namespace Http {

    /**
     * The Url Class
     */
    class Url : public Interfaces::UrlInterface {

    public:

        /**
         * Initialize a url string.
         * 
         * @param std::string & url 
         */
        Url(const std::string & url);

        /**
         * Retrieve the protocol.
         * 
         * @return std::string
         */
        virtual std::string getProtocol() const override;

    private:

        /**
         * Parse a url and return it.
         * 
         * @param std::string & url
         * @return void
         */
        void parse(std::string & url);

        /**
         * Store the url.
         * 
         * @var std::string & m_url
         */
        std::string & m_url;

        /**
         * Store the protocol.
         * 
         * @var std::string & m_prtocol
         */
        std::string & m_protocol;

    };

}


#endif // URL_H
