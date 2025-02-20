import { Box, Flex } from "@chakra-ui/react";
import React from "react";
import { QueryResultType } from "../ArangoQuery.types";
import { ProfileResultDisplayJSON } from "./ProfileResultDisplayJSON";
import { RemoveResultButton } from "./RemoveResultButton";
import { ResultTypeBox } from "./ResultTypeBox";

export const QueryProfileResult = ({
  queryResult
}: {
  queryResult: QueryResultType;
}) => {
  return (
    <Box
      height="500px"
      boxShadow="0 0 15px 0 rgba(0,0,0,0.2)"
      borderRadius="md"
      marginBottom="4"
      overflow="hidden"
    >
      <Flex padding="2" alignItems="center">
        <ResultTypeBox queryResult={queryResult} />
        <Box marginLeft="auto">
          <RemoveResultButton asyncJobId={queryResult.asyncJobId} />
        </Box>
      </Flex>
      <ProfileResultDisplayJSON defaultValue={queryResult.result} />
    </Box>
  );
};
