#ifndef RESPONSE_H
#define RESPONSE_H

#include "interfaces/response_interface.h"
#include "interfaces/stream_interface.h"


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
         * Retrieve the stream body.
         * 
         * @return const Interfaces::StreamInterface &
         */
        const Interfaces::StreamInterface & getBody() const override;

        /**
         * Retrieve the status code.
         * 
         * @return int
         */
        int getStatusCode() const override;

    private:
        //

    };

}


#endif // RESPONSE_H
