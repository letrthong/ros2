#include "NodeClientAction.h"
#include "NodeClientServices.h"
#include "NodeClientTopic.h"

class NodeClient: public NodeClientCallBack {
	
public:
	NodeClientServices getNodeClientServices();
	NodeClientAction getNodeClientAction();

private:
	NodeClientAction nodeClientAction;
	NodeClientServices nodeClientServices;
	NodeClientTopic nodeClientTopic;
}