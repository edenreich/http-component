#ifndef HTTP_STATUS_H
#define HTTP_STATUS_H


namespace Http {

    enum class StatusCode {
        OK = 200,
        CREATED = 201,
        ACCEPTED = 202,
        NON_AUTHORITATIVE_INFORMATION = 203,
        NO_CONTENT = 204
    };

}


#endif // HTTP_STATUS_H