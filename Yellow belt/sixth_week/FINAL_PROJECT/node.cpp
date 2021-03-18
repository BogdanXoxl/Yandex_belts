#include "node.h"

DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date):cmp_(cmp), date_(date) {}
EventComparisonNode::EventComparisonNode(const Comparison &cmp, std::string value): cmp_(cmp), event_(std::move(value)) {}
LogicalOperationNode::LogicalOperationNode(const LogicalOperation &logicOp, std::shared_ptr<Node> left, std::shared_ptr<Node> right):
    logicOp_(logicOp), first(std::move(left)), second(std::move(right)){}


bool EmptyNode::Evaluate(const Date &date, const std::string &event)const {return true;}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &event)const {
    Date d;
    if (date == d)
        return false;
    return compare(cmp_, date, date_);
}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event)const {
    if (event.empty())
        return false;
    return compare(cmp_, event, event_);
}

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event)const {
    if(logicOp_ == LogicalOperation::And)
        return first->Evaluate(date, event) && second->Evaluate(date, event);
    else if(logicOp_ == LogicalOperation::Or)
         return first->Evaluate(date, event) || second->Evaluate(date, event);

    return false;
}




