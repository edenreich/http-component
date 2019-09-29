#ifndef RESPONSE_INTERFACE_H
#define RESPONSE_INTERFACE_H


namespace Http {

    enum class StatusCode;

    namespace Interfaces {

        class StreamInterface;

        /**
         * The Response Interface
         */
        class ResponseInterface {

        public:

            /**
             * Virtual Destructor.
             */
            virtual ~ResponseInterface() = default;
            
            /**
             * Retrieve the body stream.
             * 
             * @return Http::Interfaces::StreamInterface *
             */
            virtual StreamInterface * getBody() = 0;

            /**
             * Retrieve the status code.
             * 
             * @return Http::StatusCode
             */
            virtual ::Http::StatusCode getStatusCode() const = 0;

        };
    }
}


#endif // RESPONSE_INTERFACE_H
