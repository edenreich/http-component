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
         * @param const std::string & url 
         */
        explicit Url(const std::string & url);

        /**
         * Retrieve the url.
         * 
         * @return std::string
         */
        std::string getUrl() const override;

        /**
         * Retrieve the encoded url.
         * 
         * @return std::string
         */
        std::string getEncodedUrl() const override;

        /**
         * Retrieve the protocol.
         * 
         * @return std::string
         */
        std::string getProtocol() const override;

        /**
         * Retrieve the host.
         * 
         * @return std::string
         */
        std::string getHost() const override;

        /**
         * Retrieve the path.
         * 
         * @return std::string
         */
        std::string getPath() const override;

    private:

        /**
         * Parse a url and return it.
         * 
         * @param std::string & url
         * @return void
         */
        void parse(const std::string & url);

        /**
         * Store the raw url.
         * 
         * @var std::string m_url
         */
        std::string m_url;

        /**
         * Store the protocol.
         * 
         * @var std::string m_prtocol
         */
        std::string m_protocol;

        /**
         * Store the host.
         * 
         * @var std::string m_host
         */
        std::string m_host;

        /**
         * Store the path.
         * 
         * @var std::string m_path
         */
        std::string m_path;

        /**
         * Store the query string.
         * 
         * @var std::string m_query
         */
        std::string m_query;

    };

}


#endif // URL_H