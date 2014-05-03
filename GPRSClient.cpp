#include <GPRSClient.h>

GPRSClient::GPRSClient() : _sock(MAX_SOCK_NUM) {
}

GPRSClient::GPRSClient(uint8_t sock) : _sock(sock) {
}

int GPRSClient::connect(const char* host, uint16_t port) {
  int n_of_at = 0;

  while(n_of_at<3) {
          if(!net_->connectTCP(server, port)) {
#ifdef DEBUG_ON
               Serial.println("DB:NOT CONN");
#endif
               n_of_at++;
          } else {
               connected=true;
               n_of_at=3;
               return 1;
          }
  }
  return 0;
}

