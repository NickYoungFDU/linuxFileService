// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "FileShareService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::azure::storage::linuxFileClient;

class FileShareServiceHandler : virtual public FileShareServiceIf {
 public:
  FileShareServiceHandler() {
    // Your initialization goes here
  }

  void MapFileShare(std::string& _return, const std::string& smbShareAddress, const std::string& username, const std::string& password, const std::string& mountPoint) {
    // Your implementation goes here
    printf("MapFileShare\n");
  }

  void UnmapFileContainer(const std::string& mountPoint) {
    // Your implementation goes here
    printf("UnmapFileContainer\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<FileShareServiceHandler> handler(new FileShareServiceHandler());
  shared_ptr<TProcessor> processor(new FileShareServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

