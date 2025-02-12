import { Button } from "@chakra-ui/react";
import React from "react";
import { getCurrentDB } from "../../../utils/arangoClient";
import { useQueryContext } from "../QueryContextProvider";

export const CancelQueryButton = ({
  asyncJobId
}: {
  asyncJobId: string;
}) => {
  const { onRemoveResult } = useQueryContext();
  const onCancel = async () => {
    try {
      await getCurrentDB().job(asyncJobId).cancel();
      onRemoveResult(asyncJobId);
      window.arangoHelper.arangoNotification("Query cancelled");
    } catch (e) {}
  };
  return (
    <Button
      marginLeft="auto"
      colorScheme="red"
      size="sm"
      aria-label="Close"
      onClick={onCancel}
    >
      Cancel
    </Button>
  );
};
