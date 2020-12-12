#include "duckdb/common/enums/physical_operator_type.hpp"

using namespace std;

namespace duckdb {

string PhysicalOperatorToString(PhysicalOperatorType type) {
	switch (type) {
	case PhysicalOperatorType::LEAF:
		return "LEAF";
	case PhysicalOperatorType::TABLE_SCAN:
		return "TABLE_SCAN";
	case PhysicalOperatorType::DUMMY_SCAN:
		return "DUMMY_SCAN";
	case PhysicalOperatorType::CHUNK_SCAN:
		return "CHUNK_SCAN";
	case PhysicalOperatorType::DELIM_SCAN:
		return "DELIM_SCAN";
	case PhysicalOperatorType::EXTERNAL_FILE_SCAN:
		return "EXTERNAL_FILE_SCAN";
	case PhysicalOperatorType::QUERY_DERIVED_SCAN:
		return "QUERY_DERIVED_SCAN";
	case PhysicalOperatorType::ORDER_BY:
		return "ORDER_BY";
	case PhysicalOperatorType::LIMIT:
		return "LIMIT";
	case PhysicalOperatorType::TOP_N:
		return "TOP_N";
	case PhysicalOperatorType::AGGREGATE:
		return "AGGREGATE";
	case PhysicalOperatorType::WINDOW:
		return "WINDOW";
	case PhysicalOperatorType::UNNEST:
		return "UNNEST";
	case PhysicalOperatorType::SIMPLE_AGGREGATE:
		return "SIMPLE_AGGREGATE";
	case PhysicalOperatorType::HASH_GROUP_BY:
		return "HASH_GROUP_BY";
	case PhysicalOperatorType::PERFECT_HASH_GROUP_BY:
		return "PERFECT_HASH_GROUP_BY";
	case PhysicalOperatorType::SORT_GROUP_BY:
		return "SORT_GROUP_BY";
	case PhysicalOperatorType::FILTER:
		return "FILTER";
	case PhysicalOperatorType::PROJECTION:
		return "PROJECTION";
	case PhysicalOperatorType::COPY_TO_FILE:
		return "COPY_TO_FILE";
	case PhysicalOperatorType::DELIM_JOIN:
		return "DELIM_JOIN";
	case PhysicalOperatorType::BLOCKWISE_NL_JOIN:
		return "BLOCKWISE_NL_JOIN";
	case PhysicalOperatorType::NESTED_LOOP_JOIN:
		return "NESTED_LOOP_JOIN";
	case PhysicalOperatorType::HASH_JOIN:
		return "HASH_JOIN";
	case PhysicalOperatorType::INDEX_JOIN:
		return "INDEX_JOIN";
	case PhysicalOperatorType::PIECEWISE_MERGE_JOIN:
		return "PIECEWISE_MERGE_JOIN";
	case PhysicalOperatorType::CROSS_PRODUCT:
		return "CROSS_PRODUCT";
	case PhysicalOperatorType::UNION:
		return "UNION";
	case PhysicalOperatorType::INSERT:
		return "INSERT";
	case PhysicalOperatorType::INSERT_SELECT:
		return "INSERT_SELECT";
	case PhysicalOperatorType::DELETE_OPERATOR:
		return "DELETE";
	case PhysicalOperatorType::UPDATE:
		return "UPDATE";
	case PhysicalOperatorType::EXPORT_EXTERNAL_FILE:
		return "EXPORT_EXTERNAL_FILE";
	case PhysicalOperatorType::EMPTY_RESULT:
		return "EMPTY_RESULT";
	case PhysicalOperatorType::CREATE:
		return "CREATE";
	case PhysicalOperatorType::CREATE_INDEX:
		return "CREATE_INDEX";
	case PhysicalOperatorType::EXPLAIN:
		return "EXPLAIN";
	case PhysicalOperatorType::EXECUTE:
		return "EXECUTE";
	case PhysicalOperatorType::VACUUM:
		return "VACUUM";
	case PhysicalOperatorType::RECURSIVE_CTE:
		return "REC_CTE";
	case PhysicalOperatorType::RECURSIVE_CTE_SCAN:
		return "REC_CTE_SCAN";
	case PhysicalOperatorType::INVALID:
		return "INVALID";
	case PhysicalOperatorType::EXPRESSION_SCAN:
		return "EXPRESSION_SCAN";
	case PhysicalOperatorType::ALTER:
		return "ALTER";
	case PhysicalOperatorType::CREATE_SEQUENCE:
		return "CREATE_SEQUENCE";
	case PhysicalOperatorType::CREATE_VIEW:
		return "CREATE_VIEW";
	case PhysicalOperatorType::CREATE_SCHEMA:
		return "CREATE_SCHEMA";
	case PhysicalOperatorType::CREATE_MACRO:
		return "CREATE_MACRO";
	case PhysicalOperatorType::DROP:
		return "DROP";
	case PhysicalOperatorType::PRAGMA:
		return "PRAGMA";
	case PhysicalOperatorType::TRANSACTION:
		return "TRANSACTION";
	case PhysicalOperatorType::PREPARE:
		return "PREPARE";
	case PhysicalOperatorType::EXPORT:
		return "EXPORT";
	}
	return "UNDEFINED";
}

} // namespace duckdb
