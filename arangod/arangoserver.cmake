add_library(arangoserver STATIC
  Actions/ActionFeature.cpp
  Actions/actions.cpp
  Actions/RestActionHandler.cpp
  Auth/Common.cpp
  Auth/TokenCache.cpp
  Auth/User.cpp
  Auth/UserManager.cpp
  Cluster/Action.cpp
  Cluster/ActionBase.cpp
  Cluster/ActionDescription.cpp
  Cluster/AgencyCache.cpp
  Cluster/AgencyCallback.cpp
  Cluster/AgencyCallbackRegistry.cpp
  Cluster/AutoRebalance.cpp
  Cluster/ClusterCollectionCreationInfo.cpp
  Cluster/ClusterFeature.cpp
  Cluster/ClusterHelpers.cpp
  Cluster/ClusterInfo.cpp
  Cluster/ClusterTrxMethods.cpp
  Cluster/ClusterTypes.cpp
  Cluster/ClusterUpgradeFeature.cpp
  Cluster/CollectionInfoCurrent.cpp
  Cluster/CreateCollection.cpp
  Cluster/CreateDatabase.cpp
  Cluster/DBServerAgencySync.cpp
  Cluster/DropCollection.cpp
  Cluster/DropDatabase.cpp
  Cluster/DropIndex.cpp
  Cluster/EnsureIndex.cpp
  Cluster/FollowerInfo.cpp
  Cluster/HeartbeatThread.cpp
  Cluster/Maintenance.cpp
  Cluster/MaintenanceFeature.cpp
  Cluster/MaintenanceRestHandler.cpp
  Cluster/MaintenanceWorker.cpp
  Cluster/RebootTracker.cpp
  Cluster/ReplicationTimeoutFeature.cpp
  Cluster/ResignShardLeadership.cpp
  Cluster/RestAgencyCallbacksHandler.cpp
  Cluster/RestClusterHandler.cpp
  Cluster/ServerDefaults.cpp
  Cluster/ServerState.cpp
  Cluster/SynchronizeShard.cpp
  Cluster/TakeoverShardLeadership.cpp
  Cluster/UpdateCollection.cpp
  Cluster/UpdateReplicatedLogAction.cpp
  FeaturePhases/AgencyFeaturePhase.cpp
  FeaturePhases/AqlFeaturePhase.cpp
  FeaturePhases/BasicFeaturePhaseServer.cpp
  FeaturePhases/ClusterFeaturePhase.cpp
  FeaturePhases/DatabaseFeaturePhase.cpp
  FeaturePhases/FinalFeaturePhase.cpp
  FeaturePhases/ServerFeaturePhase.cpp
  GeneralServer/Acceptor.cpp
  GeneralServer/AcceptorTcp.cpp
  GeneralServer/AcceptorUnixDomain.cpp
  GeneralServer/AsyncJobManager.cpp
  GeneralServer/AuthenticationFeature.cpp
  GeneralServer/CommTask.cpp
  GeneralServer/GeneralCommTask.cpp
  GeneralServer/GeneralServer.cpp
  GeneralServer/GeneralServerFeature.cpp
  GeneralServer/H2CommTask.cpp
  GeneralServer/HttpCommTask.cpp
  GeneralServer/IoContext.cpp
  GeneralServer/RequestLane.cpp
  GeneralServer/RestHandler.cpp
  GeneralServer/RestHandlerFactory.cpp
  GeneralServer/ServerSecurityFeature.cpp
  GeneralServer/SslServerFeature.cpp
  RestHandler/RestAdminClusterHandler.cpp
  RestHandler/RestAdminDatabaseHandler.cpp
  RestHandler/RestAdminLogHandler.cpp
  RestHandler/RestAdminServerHandler.cpp
  RestHandler/RestAdminStatisticsHandler.cpp
  RestHandler/RestAqlFunctionsHandler.cpp
  RestHandler/RestAuthHandler.cpp
  RestHandler/RestAuthReloadHandler.cpp
  RestHandler/RestBaseHandler.cpp
  RestHandler/RestCompactHandler.cpp
  RestHandler/RestCursorHandler.cpp
  RestHandler/RestDatabaseHandler.cpp
  RestHandler/RestDebugHandler.cpp
  RestHandler/RestDocumentHandler.cpp
  RestHandler/RestDumpHandler.cpp
  RestHandler/RestEdgesHandler.cpp
  RestHandler/RestEndpointHandler.cpp
  RestHandler/RestEngineHandler.cpp
  RestHandler/RestExplainHandler.cpp
  RestHandler/RestImportHandler.cpp
  RestHandler/RestIndexHandler.cpp
  RestHandler/RestJobHandler.cpp
  RestHandler/RestKeyGeneratorsHandler.cpp
  RestHandler/RestLicenseHandler.cpp
  RestHandler/RestOptionsBaseHandler.cpp
  RestHandler/RestOptionsDescriptionHandler.cpp
  RestHandler/RestOptionsHandler.cpp
  RestHandler/RestQueryCacheHandler.cpp
  RestHandler/RestQueryHandler.cpp
  RestHandler/RestQueryPlanCacheHandler.cpp
  RestHandler/RestShutdownHandler.cpp
  RestHandler/RestSimpleHandler.cpp
  RestHandler/RestSimpleQueryHandler.cpp
  RestHandler/RestStatusHandler.cpp
  RestHandler/RestSupervisionStateHandler.cpp
  RestHandler/RestSupportInfoHandler.cpp
  RestHandler/RestSystemReportHandler.cpp
  RestHandler/RestTelemetricsHandler.cpp
  RestHandler/RestTimeHandler.cpp
  RestHandler/RestTransactionHandler.cpp
  RestHandler/RestTtlHandler.cpp
  RestHandler/RestUploadHandler.cpp
  RestHandler/RestUsersHandler.cpp
  RestHandler/RestVersionHandler.cpp
  RestHandler/RestViewHandler.cpp
  RestHandler/RestVocbaseBaseHandler.cpp
  RestHandler/RestWalAccessHandler.cpp
  RestServer/AqlFeature.cpp
  RestServer/BootstrapFeature.cpp
  RestServer/CheckVersionFeature.cpp
  RestServer/CpuUsageFeature.cpp
  RestServer/DaemonFeature.cpp
  RestServer/DatabaseFeature.cpp
  RestServer/DatabasePathFeature.cpp
  RestServer/DumpLimitsFeature.cpp
  RestServer/EndpointFeature.cpp
  RestServer/EnvironmentFeature.cpp
  RestServer/FileDescriptorsFeature.cpp
  RestServer/FlushFeature.cpp
  RestServer/FortuneFeature.cpp
  RestServer/InitDatabaseFeature.cpp
  RestServer/IOHeartbeatThread.cpp
  RestServer/LanguageCheckFeature.cpp
  RestServer/LockfileFeature.cpp
  RestServer/LogBufferFeature.cpp
  RestServer/MaxMapCountFeature.cpp
  RestServer/NonceFeature.cpp
  RestServer/PrivilegeFeature.cpp
  RestServer/QueryRegistryFeature.cpp
  RestServer/ServerFeature.cpp
  RestServer/ServerIdFeature.cpp
  RestServer/SharedPRNGFeature.cpp
  RestServer/SoftShutdownFeature.cpp
  RestServer/SupervisorFeature.cpp
  RestServer/SystemDatabaseFeature.cpp
  RestServer/TemporaryStorageFeature.cpp
  RestServer/TimeZoneFeature.cpp
  RestServer/TtlFeature.cpp
  RestServer/UpgradeFeature.cpp
  RestServer/ViewTypesFeature.cpp
  RestServer/VocbaseContext.cpp
  RestServer/VectorIndexFeature.cpp
  Scheduler/LockfreeThreadPool.cpp
  Scheduler/Scheduler.cpp
  Scheduler/SchedulerFeature.cpp
  Scheduler/SchedulerMetrics.cpp
  Scheduler/SimpleThreadPool.cpp
  Scheduler/SupervisedScheduler.cpp
  Scheduler/ThreadPoolScheduler.cpp
  Scheduler/ThreadPoolScheduler.cpp
  Scheduler/WorkStealingThreadPool.cpp
  Sharding/ShardDistributionReporter.cpp
  Sharding/ShardingFeature.cpp
  Sharding/ShardingInfo.cpp
  Sharding/ShardingStrategy.cpp
  Sharding/ShardingStrategyDefault.cpp
  Statistics/ConnectionStatistics.cpp
  Statistics/Descriptions.cpp
  Statistics/RequestStatistics.cpp
  Statistics/ServerStatistics.cpp
  Statistics/StatisticsFeature.cpp
  Statistics/StatisticsWorker.cpp
  Transaction/BatchOptions.cpp
  Transaction/ClusterUtils.cpp
  Transaction/Context.cpp
  Transaction/CountCache.cpp
  Transaction/Helpers.cpp
  Transaction/Hints.cpp
  Transaction/History.cpp
  Transaction/IndexesSnapshot.cpp
  Transaction/ManagedContext.cpp
  Transaction/Manager.cpp
  Transaction/ManagerFeature.cpp
  Transaction/Methods.cpp
  Transaction/Options.cpp
  Transaction/ReplicatedContext.cpp
  Transaction/SmartContext.cpp
  Transaction/StandaloneContext.cpp
  Transaction/Status.cpp)
if (USE_V8) 
  target_sources(arangoserver PRIVATE
    FeaturePhases/FoxxFeaturePhase.cpp
    FeaturePhases/V8FeaturePhase.cpp
    RestHandler/RestAdminExecuteHandler.cpp
    RestHandler/RestAdminRoutingHandler.cpp
    RestHandler/RestAqlUserFunctionsHandler.cpp
    RestHandler/RestTasksHandler.cpp
    RestServer/ConsoleFeature.cpp
    RestServer/ConsoleThread.cpp
    RestServer/FrontendFeature.cpp
    RestServer/ScriptFeature.cpp)
endif()
if (USE_MAINTAINER_MODE)
  target_sources(arangoserver PRIVATE
    RestHandler/RestTestHandler.cpp)
endif()

target_link_libraries(arangoserver
  arango_agency
  arango_aql
  arango_cluster_engine
  arango_cluster_methods
  arango_common_rest_handler
  arango_futures
  arango_geo
  arango_graph
  arango_indexes
  arango_inspection
  arango_iresearch
  arango_metrics
  arango_network
  arango_replication
  arango_storage_engine
  arango_utils
  arango_vocbase
  boost_boost
  ${MSVC_LIBS})
if (MSVC)
  target_link_libraries(arangoserver Bcrypt.lib)
endif()

if (USE_V8)
  target_link_libraries(arangoserver arango_v8server)
endif()

target_include_directories(arangoserver PRIVATE
  "${PROJECT_SOURCE_DIR}/arangod"
  "${PROJECT_SOURCE_DIR}/${ENTERPRISE_INCLUDE_DIR}")

add_dependencies(arangoserver tzdata)
