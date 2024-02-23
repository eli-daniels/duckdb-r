#pragma once

#include "cpp11.hpp"

#include <Rdefines.h>
#include <R_ext/Altrep.h>
#include <Rversion.h>

#include "duckdb.hpp"
#include "duckdb/function/table_function.hpp"
#include "duckdb/common/unordered_map.hpp"
#include "duckdb/parser/tableref/table_function_ref.hpp"
#include "duckdb/common/mutex.hpp"

#if defined(R_VERSION) && R_VERSION >= R_Version(4, 3, 0)
#define R_HAS_ALTLIST
#endif

namespace duckdb {

typedef unordered_map<std::string, SEXP> arrow_scans_t;

struct DBWrapper {
	duckdb::unique_ptr<DuckDB> db;
	arrow_scans_t arrow_scans;
	mutex lock;
};

void DBDeleter(DBWrapper *);
typedef cpp11::external_pointer<DBWrapper, DBDeleter> db_eptr_t;

struct ConnWrapper {
	duckdb::unique_ptr<Connection> conn;
	db_eptr_t db_eptr;
};

void ConnDeleter(ConnWrapper *);
typedef cpp11::external_pointer<ConnWrapper, ConnDeleter> conn_eptr_t;

struct RStatement {
	duckdb::unique_ptr<PreparedStatement> stmt;
	vector<Value> parameters;
};

struct RelationWrapper {
	RelationWrapper(std::shared_ptr<Relation> rel_p) : rel(std::move(rel_p)) {
	}
	shared_ptr<Relation> rel;
};

typedef cpp11::external_pointer<ParsedExpression> expr_extptr_t;
typedef cpp11::external_pointer<RelationWrapper> rel_extptr_t;

typedef cpp11::external_pointer<RStatement> stmt_eptr_t;

struct RQueryResult {
	duckdb::unique_ptr<QueryResult> result;
};

typedef cpp11::external_pointer<RQueryResult> rqry_eptr_t;

// internal
unique_ptr<TableRef> ArrowScanReplacement(ClientContext &context, const std::string &table_name,
                                          ReplacementScanData *data);

struct ArrowScanReplacementData : public ReplacementScanData {
	DBWrapper *wrapper;
};

cpp11::strings StringsToSexp(vector<std::string> s);

SEXP ToUtf8(SEXP string_sexp);

static constexpr char R_STRING_TYPE_NAME[] = "r_string";

struct RStringsType {
	static LogicalType Get();
};

struct DataFrameScanFunction : public TableFunction {
	DataFrameScanFunction();
};

struct RStrings {
	SEXP secs; // Rf_mkChar
	SEXP mins;
	SEXP hours;
	SEXP days;
	SEXP weeks;
	SEXP POSIXct;
	SEXP POSIXt;
	SEXP UTC_str; // Rf_mkString
	SEXP Date_str;
	SEXP factor_str;
	SEXP dataframe_str;
	SEXP difftime_str;
	SEXP secs_str;
	SEXP arrow_str; // StringsToSexp
	SEXP POSIXct_POSIXt_str;
	SEXP integer64_str;
	SEXP enc2utf8_sym; // Rf_install
	SEXP tzone_sym;
	SEXP units_sym;
	SEXP getNamespace_sym;
	SEXP Table__from_record_batches_sym;
	SEXP ImportSchema_sym;
	SEXP ImportRecordBatch_sym;
	SEXP ImportRecordBatchReader_sym;
	SEXP materialize_sym;
	SEXP duckdb_row_names_sym;
	SEXP duckdb_vector_sym;

	static const RStrings &get() {
		// On demand
		static RStrings strings;
		return strings;
	}

private:
	RStrings();
};

SEXP duckdb_execute_R_impl(MaterializedQueryResult *result, bool);

} // namespace duckdb

// moved out of duckdb namespace for the time being (r-lib/cpp11#262)

duckdb::db_eptr_t rapi_startup(std::string, bool, cpp11::list);

void rapi_shutdown(duckdb::db_eptr_t);

duckdb::conn_eptr_t rapi_connect(duckdb::db_eptr_t);

void rapi_disconnect(duckdb::conn_eptr_t);

cpp11::list rapi_prepare(duckdb::conn_eptr_t, std::string);

cpp11::list rapi_bind(duckdb::stmt_eptr_t, SEXP paramsexp, bool);

SEXP rapi_execute(duckdb::stmt_eptr_t, bool, bool);

void rapi_release(duckdb::stmt_eptr_t);

void rapi_register_df(duckdb::conn_eptr_t, std::string, cpp11::data_frame, bool);

void rapi_unregister_df(duckdb::conn_eptr_t, std::string);

void rapi_register_arrow(duckdb::conn_eptr_t, SEXP namesexp, SEXP export_funsexp, SEXP valuesexp);

void rapi_unregister_arrow(duckdb::conn_eptr_t, SEXP namesexp);

SEXP rapi_execute_arrow(duckdb::rqry_eptr_t, int);

SEXP rapi_record_batch(duckdb::rqry_eptr_t, int);

cpp11::r_string rapi_ptr_to_str(SEXP extptr);

void duckdb_r_transform(duckdb::Vector &src_vec, SEXP dest, duckdb::idx_t dest_offset, duckdb::idx_t n, bool integer64);
SEXP duckdb_r_allocate(const duckdb::LogicalType &type, duckdb::idx_t nrows);
void duckdb_r_decorate(const duckdb::LogicalType &type, SEXP dest, bool integer64);
