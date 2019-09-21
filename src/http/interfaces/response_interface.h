#ifndef RESPONSE_INTERFACE_H
#define RESPONSE_INTERFACE_H


namespace Http {
    namespace Interfaces {

        class StreamInterface;

        /**
         * The Response Interface
         */
        class ResponseInterface {

        public:
            
            /**
             * Retrieve the stream body.
             * 
             * @return ResponseBodyInterface
             */
            virtual StreamInterface getBody() const = 0;

            /**
             * Retrieve the status code.
             * 
             * @return int
             */
            virtual int getStatusCode() const = 0;

        };
    }
}


#endif // RESPONSE_INTERFACE_H
