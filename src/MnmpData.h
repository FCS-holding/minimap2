#ifndef MNMP_FLOW_DATA_H
#define MNMP_FLOW_DATA_H

#include <string>
#include <vector>
#include "bseq.h"
#include "mmpriv.h"
#include "minimap.h"
#include "htslib/sam.h"
#include "kseq.h"
#include "kflow/Queue.h"

#include "BamFileBuffer.h"
#include "MnmpStagesCommon.h"

KSEQ_INIT2(static , gzFile, gzread)

// Data structure for kseqs read circulate memory
struct kseq_buf
{
  kseq_t * ks;
  int size;
};

// Kseq_queue for circulate memory
extern kestrelFlow::Queue<kseq_buf, INPUT_DEPTH + 1> kseq_queue;

//Data structure for kseqsRead and bseqsRead
struct KseqsBatch
{
  int m_startSeqIdx;
  int m_batchIdx;
  int m_numSeq;
  kseq_buf kseqs_buf;
};

//Data structure for sort-merge pipe
struct BamRecord {
  int id; 
  int size;
  bam1_t ** bams;

  BamFileBuffer* fbuf;
};

struct fragExtSOA {
  mm_seg_t **m_segChainsArr;
};

fragExtSOA *createFragmentExtensionSOA(int);
void deleteFragmentExtensionSOA(fragExtSOA *);

struct SeqsBatch {
  int         m_batchIdx;
  int         m_startSeqIdx;
  int         m_numSeq; // n_seq
  mm_bseq1_t *m_seqs;

  int  m_numFrag;
  int *m_numReg;
  int *m_segOff;
  int *m_numSeg;
  int *m_repLen;
  int *m_fragGap;

  mm_reg1_t **m_reg;

  //std::string name_tag = "SeqsBatch"; 
};

struct ChainsBatch {
  int         m_batchIdx;
  int         m_startSeqIdx;
  int         m_numSeq; // n_seq
  mm_bseq1_t *m_seqs;

  int  m_numFrag;
  int *m_numReg;
  int *m_segOff;
  int *m_numSeg;
  int *m_repLen;
  int *m_fragGap;

  mm_reg1_t **m_reg;

  fragExtSOA *m_fragExtSOA;

  //std::string name_tag = "ChainsBatch";
};


struct AlignsBatch {
  int         m_batchIdx;
  int         m_startSeqIdx;
  int         m_numSeq; // n_seq
  mm_bseq1_t *m_seqs;

  int  m_numFrag;
  int *m_numReg;
  int *m_segOff;
  int *m_numSeg;
  int *m_repLen;
  int *m_fragGap;

  mm_reg1_t **m_reg;

  //std::string name_tag = "AlignsBatch";
};

struct AlignsBundle {
  int                       m_bundleIdx;
  std::vector<AlignsBatch> *m_batches;
};

struct BamsBatch {
  int      m_batchIdx;
  int      m_numBams;
  bam1_t **m_bams;
};


#endif
