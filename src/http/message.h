#ifndef MESSAGE_H
#define MESSAGE_H

#include "interfaces/message_interface.h"


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
         * @return const std::string &
         */
        const std::string & getProtocolLine() const override;

        /**
         * Retrieve the message headers.
         * 
         * @return Http::Headers
         */
        Headers getHeaders() const override;

        /**
         * Retrieve the body stream.
         * 
         * @return const std::stringstream &
         */
        const std::stringstream & getBody() const override;

        /**
         * Retrieve the raw message
         * with the protocol line,
         * headers and body.
         * 
         * @return const std::stringstream &
         */
        const std::stringstream & getRaw() const override;

    private:

        /**
         * Parse the message content.
         * 
         * @param const std::string & content
         * @return void
         */
        void parse(const std::string & content);

        /**
         * Store the message content.
         * 
         * @var std::stringstream
         */
        std::stringstream m_content;

        /**
         * Store the protocol line.
         * 
         * @var std::string
         */
        std::string m_protocolLine;

        /**
         * Store the headers.
         * 
         * @var Http::headers
         */
        Headers m_headers;

        /**
         * Store the body of the message.
         * 
         * @var std::stringstream
         */
        std::stringstream m_body;

    };

}


#endif // MESSAGE_H
