#ifndef RESPONSE_H
#define RESPONSE_H

#include "interfaces/response_interface.h"
#include "interfaces/stream_interface.h"
#include "types/status_codes.h"


namespace Http {

    /**
     * The Response Class
     */
    class Response : public Interfaces::ResponseInterface {

    public:

        /**
         * Construct a response.
         */
        Response();

        /**
         * Construct a response.
         * 
         * - Initialize a stream
         * 
         * @param Http::Interfaces::StreamInterface * stream
         */
        Response(Interfaces::StreamInterface * stream);

        /**
         * Destruct the response.
         */
        ~Response();

        /**
         * Retrieve the body stream.
         * 
         * @return Http::Interfaces::StreamInterface *
         */
        Interfaces::StreamInterface * getBody() override;

        /**
         * Retrieve the status code.
         * 
         * @return Http::StatusCode
         */
        StatusCode getStatusCode() const override;

    private:

        /**
         * Store the stream interface.
         * 
         * @var Http::Interfaces::StreamInterface *
         */
        Interfaces::StreamInterface * m_stream;

    };

}


#endif // RESPONSE_H
