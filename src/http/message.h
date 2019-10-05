#ifndef MESSAGE_H
#define MESSAGE_H

#include "interfaces/message_interface.h"
#include "interfaces/client_socket_interface.h"

#include <sstream>


namespace Http {

    /**
     * The Message Class
     */
    class Message : public Interfaces::MessageInterface {

    public:

        /**
         * Construct a message.
         * 
         * @param const std::string & content
         */
        Message(const std::string & content);

        /**
         * Construct a message.
         * 
         * @param const std::stringstream & content
         */
        Message(const std::stringstream & content);

        /**
         * Destruct the message.
         */
        ~Message();

        /**
         * Get the first line of the message.
         * 
         * @return std::string
         */
        std::string getProtocolLine() const override;

        /**
         * Retrieve the message headers.
         * 
         * @return Http::Headers
         */
        Headers getHeaders() const override;

        /**
         * Retrieve the body stream.
         * 
         * @return std::stringstream
         */
        std::stringstream getBody() const override;

    private:

        /**
         * Store the message content.
         * 
         * @var std::stringstream
         */
        std::stringstream m_content;

    };

}


#endif // MESSAGE_H
