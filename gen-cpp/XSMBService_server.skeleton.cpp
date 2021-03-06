// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "XSMBService.h"
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

class XSMBServiceHandler : virtual public XSMBServiceIf {
 public:
  XSMBServiceHandler() {
    // Your initialization goes here
  }

  bool CreateDirectory(const std::string& dirPath) {
    // Your implementation goes here
    printf("CreateDirectory\n");
  }

  bool DeleteDirectory(const std::string& dirPath, const bool isRecursive) {
    // Your implementation goes here
    printf("DeleteDirectory\n");
  }

  bool CreateFile(const std::string& filePath, const int64_t fileSize, const bool noBuffering) {
    // Your implementation goes here
    printf("CreateFile\n");
  }

  bool DeleteFile(const std::string& filePath) {
    // Your implementation goes here
    printf("DeleteFile\n");
  }

  bool ReadFile(const std::string& filePath, const StreamDataLayout& data, const bool noBuffering, const int8_t fileVersion, const bool useVersionInData, const std::string& keyName) {
    // Your implementation goes here
    printf("ReadFile\n");
  }

  bool WriteFile(const std::string& filePath, const StreamDataLayout& data, const bool noBuffering, const int8_t fileVersion, const bool useVersionInData, const std::string& keyName) {
    // Your implementation goes here
    printf("WriteFile\n");
  }

  bool ListCloudFiles(const std::string& dirPath, const bool isRecursive, const std::map<std::string, MatchInformation::type> & files, const std::map<std::string, MatchInformation::type> & dirs) {
    // Your implementation goes here
    printf("ListCloudFiles\n");
  }

  int64_t GetCloudFileLength(const std::string& filePath) {
    // Your implementation goes here
    printf("GetCloudFileLength\n");
  }

  bool SetCloudFileLength(const std::string& filePath, const int64_t fileLength) {
    // Your implementation goes here
    printf("SetCloudFileLength\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<XSMBServiceHandler> handler(new XSMBServiceHandler());
  shared_ptr<TProcessor> processor(new XSMBServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

